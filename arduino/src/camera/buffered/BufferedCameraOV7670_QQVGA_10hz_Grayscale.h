//
// Created by indrek on 30.04.2016.
//

#ifndef _BUFFEREDCAMERAOV7670_QQVGA_10HZ_GRAYSCALE_H
#define _BUFFEREDCAMERAOV7670_QQVGA_10HZ_GRAYSCALE_H

#include "BufferedCameraOV7670.h"


// 160 x 120 @ 10Hz
class BufferedCameraOV7670_QQVGA_10hz_Grayscale : public BufferedCameraOV7670<uint8_t, 160, uint8_t, 160, uint8_t, 120> {


public:
    BufferedCameraOV7670_QQVGA_10hz_Grayscale() : BufferedCameraOV7670(Resolution::RESOLUTION_QQVGA_160x120, CameraOV7670::PIXEL_YUV422, 0) {};

  inline void readLine() override __attribute__((always_inline));


private:
  inline void readPixels_unrolled_x160(uint16_t byteIndex) __attribute__((always_inline));
  inline void readPixels_unrolled_x10(uint16_t byteIndex) __attribute__((always_inline));
  inline void readPixel_unrolled(uint16_t byteIndex) __attribute__((always_inline));

};




void BufferedCameraOV7670_QQVGA_10hz_Grayscale::readLine() {
  pixelBuffer.writeBufferPadding = 0;
  waitForPixelClockLow();

  // only way to get line data at 10Hz is to unroll pixel reading
  readPixels_unrolled_x160(0);
}


#define BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X160_STEP 10
void BufferedCameraOV7670_QQVGA_10hz_Grayscale::readPixels_unrolled_x160(uint16_t byteIndex) {
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X160_STEP * 0);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X160_STEP * 1);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X160_STEP * 2);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X160_STEP * 3);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X160_STEP * 4);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X160_STEP * 5);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X160_STEP * 6);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X160_STEP * 7);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X160_STEP * 8);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X160_STEP * 9);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X160_STEP * 10);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X160_STEP * 11);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X160_STEP * 12);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X160_STEP * 13);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X160_STEP * 14);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X160_STEP * 15);
}

#define BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X10_STEP 1
void BufferedCameraOV7670_QQVGA_10hz_Grayscale::readPixels_unrolled_x10(uint16_t byteIndex) {
  readPixel_unrolled(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X10_STEP * 0);
  readPixel_unrolled(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X10_STEP * 1);
  readPixel_unrolled(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X10_STEP * 2);
  readPixel_unrolled(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X10_STEP * 3);
  readPixel_unrolled(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X10_STEP * 4);
  readPixel_unrolled(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X10_STEP * 5);
  readPixel_unrolled(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X10_STEP * 6);
  readPixel_unrolled(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X10_STEP * 7);
  readPixel_unrolled(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X10_STEP * 8);
  readPixel_unrolled(byteIndex + BufferedCameraOV7670_QQVGA_10hz_Grayscale_READ_PIXEL_X10_STEP * 9);
}

void BufferedCameraOV7670_QQVGA_10hz_Grayscale::readPixel_unrolled(uint16_t byteIndex) {
  asm volatile("nop");
  pixelBuffer.writeBuffer[byteIndex] = readPixelByte();
  asm volatile("nop");
  // for grayscale we are only interested in the second byte
  pixelBuffer.writeBuffer[byteIndex] = readPixelByte();
}




#endif //_BUFFEREDCAMERAOV7670_QQVGA_10HZ_GRAYSCALE_H
