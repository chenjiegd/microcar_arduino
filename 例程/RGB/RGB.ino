#define wusicaijuan chenshuaiqi

#include <Adafruit_NeoPixel.h> //库文件
#define PIN 13				   //定义RGB灯的引脚
#define MAX_LED 4			   //小车一共有4个RGB灯

Adafruit_NeoPixel strip = Adafruit_NeoPixel(MAX_LED, PIN, NEO_RGB + NEO_KHZ800);
uint8_t i = 0;
uint32_t color = strip.Color(0, 255, 0); //绿红蓝
uint8_t brightness = 0;					 //LED的亮度
uint8_t fadeAmount = 1;					 //亮度变化增量

void setup()
{
	// put your setup code here, to run once:
	strip.begin();
	strip.show();
}

void loop()
{
	// put your main code here, to run repeatedly:
	// strip.setPixelColor(i, color);  //设置i的值控制点亮灯的序号，color控制灯的颜，这里是让0号灯为红色
	// strip.show();

	// all_RGB(255, 0, 0);
	// delay(1000);
	// all_RGB(0, 255, 0);
	// delay(1000);
	// all_RGB(0, 0, 255);
	// delay(1000);
	// strip.clear();
	// strip.show();
	// delay(1000);

	water_light(255, 0, 0, 100);

	horse_light(255, 0, 0, 100);

	breathing_light(255, 1000, 5, 5);
}

/**
* Function       all_RGB
* @author        wusicaijuan
* @date          2019.06.04
* @brief         全部RGB灯亮
* @param[in1]    R
* @param[in2]    G
* @param[in3]    B
* @retval        void
* @par History   无
*/
void all_RGB(int R, int G, int B)
{
	uint32_t color = strip.Color(G, R, B);
	for (uint8_t i = 0; i < 4; i++)
	{
		strip.setPixelColor(i, color);
	}
	strip.show();
}

/**
* Function       water_light
* @author        wusicaijuan
* @date          2019.06.04
* @brief         流水灯
* @param[in1]    R
* @param[in2]    G
* @param[in3]    B
* @param[in4]    time
* @retval        void
* @par History   无
*/
void water_light(int R, int G, int B, int time)
{
	uint32_t color = strip.Color(G, R, B);
	uint32_t quench = strip.Color(0, 0, 0);
	for (uint8_t i = 0; i <= 4; i++)
	{
		for (uint8_t j = 0; j <= i; j++)
		{
			strip.setPixelColor(j, color);
			strip.show();
			delay(time);
		}
	}
	for (uint8_t i = 5; i >= 1; i--)
	{
		for (uint8_t j = 5; j >= i; j--)
		{
			strip.setPixelColor(j - i, quench);
			strip.show();
			delay(time);
		}
	}
}

/**
* Function       horse_light
* @author        wusicaijuan
* @date          2019.06.06
* @brief         跑马灯
* @param[in1]    R
* @param[in2]    G
* @param[in3]    B
* @param[in4]    time
* @retval        void
* @par History   无
*/
void horse_light(int R, int G, int B, int time)
{
	uint32_t color = strip.Color(G, R, B);
	uint32_t quench = strip.Color(0, 0, 0);
	for (uint8_t i = 0; i < 4; i++)
	{
		strip.setPixelColor(i, color);
		strip.show();
		delay(time);
		strip.setPixelColor(i, quench);
		strip.show();
	}
}

/**
* Function       breathing_light
* @author        wusicaijuan
* @date          2019.06.06
* @brief         呼吸灯
* @param[in1]    brightness
* @param[in2]    time
* @param[in3]    increament
* @param[in4]    decreament
* @retval        void
* @par History   无
*/
void breathing_light(int brightness, int time, int increament, int decreament)
{
	uint32_t color;
	for (int b = 0; b < brightness; b += increament)
	{
		color = strip.Color(b, 0, 0);
		for (uint8_t i = 0; i < 4; i++)
		{
			strip.setPixelColor(i, color);
		}
		strip.show();
		delay(time / (255 / decreament));
	}
	for (int b = 255; b > 0; b -= increament)
	{
		color = strip.Color(b, 0, 0);
		for (uint8_t i = 0; i < 4; i++)
		{
			strip.setPixelColor(i, color);
		}
		strip.show();
		delay(time / (255 / decreament));
	}
}