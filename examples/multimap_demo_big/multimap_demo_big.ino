//
//    FILE: multimap_demo.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: minimal demo
//     URL: https://github.com/RobTillaart/MultiMap
//     URL: https://forum.arduino.cc/t/messy-math-with-map-and-pow/1275821
//          https://wokwi.com/projects/401812192306752513


#include "MultiMap.h"

//  not the IN array is not equidistant.
//  layout is to see the points of the graph.
uint16_t in[300];
int16_t out[300];


void setup()
{
  //  while(!Serial);
  Serial.begin(115200);
  Serial.println();
  Serial.println(__FILE__);
  Serial.print("MULTIMAP_LIB_VERSION: ");
  Serial.println(MULTIMAP_LIB_VERSION);
  Serial.println();

  Serial.println("X\tY");

  for (int i = 0; i < 300; i++)
  {
    in[i] = i * 3;
    out[i] = 32767 * sin(i * 0.1);
  }


  for (int i = 0; i <= 500; i++)
  {
    int16_t y = multiMap<uint16_t, int16_t>(i, in, out, 300);
    Serial.print(i);
    Serial.print("\t");
    Serial.println(y * 0.01);
  }
}


void loop()
{
}


//  -- END OF FILE --
