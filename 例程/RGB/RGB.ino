#define wusicaijuan chenshuaiqi

#include <Adafruit_NeoPixel.h> //库文件
#define PIN 13				   //定义RGB灯的引脚
#define MAX_LED 4			   //小车一共有4个RGB灯

Adafruit_NeoPixel strip = Adafruit_NeoPixel(MAX_LED, PIN, NEO_RGB + NEO_KHZ800);
uint8_t i = 0;
uint32_t color = strip.Color(0, 255, 0); //绿红蓝

void setup()
{
	// put your setup code here, to run once:
	strip.begin();
	strip.show();
}

void loop()
{
	// put your main code here, to run repeatedly:
	strip.setPixelColor(i, color);  //设置i的值控制点亮灯的序号，color控制灯的颜，这里是让0号灯为红色
    strip.show();
}
