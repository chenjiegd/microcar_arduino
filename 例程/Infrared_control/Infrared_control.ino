//wusicaijuan

//FF00FF	开关
//FF807F	前进
//FF40BF	灯
//FF20DF	左转
//FFA05F	喇叭
//FF609F	右转
//FF10EF	左旋
//FF906F	后退
//FF50AF	右旋
//FF30CF	加号
//FFB04F	0
//FF708F	减号
//FF08F7	1
//FF8877	2
//FF48B7	3
//FF28D7	4
//FFA857	5
//FF6897	6
//FF18E7	7
//FF9867	8
//FF58A7	9

#include <IRremote.h>

#define ON 1  //使能LED
#define OFF 0 //禁止LED

//定义电机的引脚
#define L_Motor_PIN1 11 //前
#define L_Motor_PIN2 10 //后
#define R_Motor_PIN1 9  //后
#define R_Motor_PIN2 6  //前

int RECV_PIN = 2; //定义红外接收器的引脚为2
IRrecv irrecv(RECV_PIN);
decode_results results;

int on = 0;//标志位
unsigned long last = millis();

long flag_run = 

void setup()
{
	// put your setup code here, to run once:
	Serial.begin(9600);
	irrecv.enableIRIn(); // 初始化红外接收器

	pinMode(L_Motor_PIN1, OUTPUT);
	pinMode(L_Motor_PIN2, OUTPUT);
	pinMode(R_Motor_PIN1, OUTPUT);
	pinMode(R_Motor_PIN2, OUTPUT);
}

void loop()
{
	// put your main code here, to run repeatedly:
	if (irrecv.decode(&results))
	{
		Serial.print("irCode: ");
		Serial.print(results.value, HEX); //以16进制换行输出接收代码
		// Serial.println();					//为了便于观看输出结果增加一个空行
		//results.value 是unsigned long型，头文件有介绍
		delay(100); //按键消抖
		Serial.print(", bits: ");
		Serial.println(results.bits); // 红外线码元位数
		irrecv.resume();			  // 接收下一个值
	}
}

/**
* Function       whistle
* @author        wusicaijuan
* @date          2019.06.04
* @brief         鸣笛
* @param[in1]    void
* @retval        void
* @par History   无
*/
void whistle() //鸣笛
{
	for (i = 0; i < 50; i++)
	{
		digitalWrite(buzzer, HIGH); //发声音
		delay(3);					//延时
		digitalWrite(buzzer, LOW);  //不发声音
		delay(1);					//延时
	}
}

/**
* Function       run
* @author        wusicaijuan
* @date          2019.06.04
* @brief         小车前进
* @param[in]     Speed
* @param[out]    void
* @retval        void
* @par History   无
*/
void run(int Speed)
{
	digitalWrite(L_Motor_PIN1, HIGH);
	digitalWrite(L_Motor_PIN2, LOW);
	digitalWrite(R_Motor_PIN1, LOW);
	digitalWrite(R_Motor_PIN2, HIGH);
	analogWrite(L_Motor_PIN1, Speed);
	analogWrite(L_Motor_PIN2, 0);
	analogWrite(R_Motor_PIN1, 0);
	analogWrite(R_Motor_PIN2, Speed);
}

/**
* Function       back
* @author        wusicaijuan
* @date          2019.06.04
* @brief         小车后退
* @param[in]     Speed
* @param[out]    void
* @retval        void
* @par History   无
*/
void back(int Speed)
{
	digitalWrite(L_Motor_PIN1, LOW);
	digitalWrite(L_Motor_PIN2, HIGH);
	analogWrite(L_Motor_PIN1, 0);
	analogWrite(L_Motor_PIN2, Speed);
	digitalWrite(R_Motor_PIN1, HIGH);
	digitalWrite(R_Motor_PIN2, LOW);
	analogWrite(R_Motor_PIN1, Speed);
	analogWrite(R_Motor_PIN2, 0);
}

/**
* Function       left
* @author        wusicaijuan
* @date          2019.06.04
* @brief         小车左转
* @param[in]     Speed
* @param[out]    void
* @retval        void
* @par History   无
*/
void left(int Speed)
{
	digitalWrite(L_Motor_PIN1, LOW);
	digitalWrite(L_Motor_PIN2, LOW);
	analogWrite(L_Motor_PIN1, 0);
	analogWrite(L_Motor_PIN2, 0);
	digitalWrite(R_Motor_PIN1, LOW);
	digitalWrite(R_Motor_PIN2, HIGH);
	analogWrite(R_Motor_PIN1, 0);
	analogWrite(R_Motor_PIN2, Speed);
}

/**
* Function       right
* @author        wusicaijuan
* @date          2019.06.04
* @brief         小车右转
* @param[in]     Speed
* @param[out]    void
* @retval        void
* @par History   无
*/
void right(int Speed)
{
	digitalWrite(L_Motor_PIN1, HIGH);
	digitalWrite(L_Motor_PIN2, LOW);
	analogWrite(L_Motor_PIN1, Speed);
	analogWrite(L_Motor_PIN2, 0);
	digitalWrite(R_Motor_PIN1, LOW);
	digitalWrite(R_Motor_PIN2, LOW);
	analogWrite(R_Motor_PIN1, 0);
	analogWrite(R_Motor_PIN2, 0);
}

/**
* Function       spin_left
* @author        wusicaijuan
* @date          2019.06.04
* @brief         小车左旋
* @param[in]     Speed
* @param[out]    void
* @retval        void
* @par History   无
*/
void spin_left(int Speed)
{
	digitalWrite(L_Motor_PIN1, LOW);
	digitalWrite(L_Motor_PIN2, HIGH);
	analogWrite(L_Motor_PIN1, 0);
	analogWrite(L_Motor_PIN2, Speed);
	digitalWrite(R_Motor_PIN1, LOW);
	digitalWrite(R_Motor_PIN2, HIGH);
	analogWrite(R_Motor_PIN1, 0);
	analogWrite(R_Motor_PIN2, Speed);
}

/**
* Function       spin_right
* @author        wusicaijuan
* @date          2019.06.04
* @brief         小车右旋
* @param[in]     Speed
* @param[out]    void
* @retval        void
* @par History   无
*/
void spin_right(int Speed)
{
	digitalWrite(L_Motor_PIN1, HIGH);
	digitalWrite(L_Motor_PIN2, LOW);
	analogWrite(L_Motor_PIN1, Speed);
	analogWrite(L_Motor_PIN2, 0);
	digitalWrite(R_Motor_PIN1, HIGH);
	digitalWrite(R_Motor_PIN2, LOW);
	analogWrite(R_Motor_PIN1, Speed);
	analogWrite(R_Motor_PIN2, 0);
}

/**
* Function       stop
* @author        wusicaijuan
* @date          2019.06.04
* @brief         小车停止
* @param[in]     Speed
* @param[out]    void
* @retval        void
* @par History   无
*/
void stop()
{
	digitalWrite(L_Motor_PIN1, LOW);
	digitalWrite(L_Motor_PIN2, LOW);
	analogWrite(L_Motor_PIN1, 0);
	analogWrite(L_Motor_PIN2, 0);
	digitalWrite(R_Motor_PIN1, LOW);
	digitalWrite(R_Motor_PIN2, LOW);
	analogWrite(R_Motor_PIN1, 0);
	analogWrite(R_Motor_PIN2, 0);
}