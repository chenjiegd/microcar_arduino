//wusicaijuan
//本实验不可调节电机速度，调节PWM值会影响红外的信号接收

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

uint8_t i;
int buzzer = 12; //设置控制蜂鸣器的引脚
int blink = 13;
int key = 8; //按键key

int RECV_PIN = 2; //定义红外接收器的引脚为2
IRrecv irrecv(RECV_PIN);
decode_results results;

int on = 0; //标志位
unsigned long last = millis();

long flag_switch = 0xFF00FF;	 //开关
long flag_run = 0xFF807F;		 //前进
long flag_led = 0xFF40BF;		 //灯
long flag_left = 0xFF20DF;		 //左转
long flag_buzzer = 0xFFA05F;	 //喇叭
long flag_right = 0xFF609F;		 //右转
long flag_spin_left = 0xFF10EF;  //左旋
long flag_back = 0xFF906F;		 //后退
long flag_spin_right = 0xFF50AF; //右旋
long flag_plus = 0xFF30CF;		 //加号
long flag_zero = 0xFFB04F;		 //0
long flag_minus = 0xFF708F;		 //减号
long flag_one = 0xFF08F7;		 //1
long flag_two = 0xFF8877;		 //2
long flag_three = 0xFF48B7;		 //3
long flag_four = 0xFF28D7;		 //4
long flag_five = 0xFFA857;		 //5
long flag_six = 0xFF6897;		 //6
long flag_seven = 0xFF18E7;		 //7
long flag_eight = 0xFF9867;		 //8
long flag_nine = 0xFF58A7;		 //9

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
	// if (irrecv.decode(&results))
	// {
	// 	Serial.print("irCode: ");
	// 	Serial.print(results.value, HEX); //以16进制换行输出接收代码
	// 	// Serial.println();					//为了便于观看输出结果增加一个空行
	// 	//results.value 是unsigned long型，头文件有介绍
	// 	delay(100); //按键消抖
	// 	Serial.print(", bits: ");
	// 	Serial.println(results.bits); // 红外线码元位数
	// 	irrecv.resume();			  // 接收下一个值
	// }

	if (irrecv.decode(&results)) //调用库函数：解码
	{
		if (millis() - last > 250) //确定接收到信号
		{
			on = !on; //标志位置反
			digitalWrite(13, on ? HIGH : LOW);
			dump(&results);
		}
		if (results.value == flag_switch)
		{
			/* code */
		}
		else if (results.value == flag_run)
		{
			/* code */
			run(200);
		}
		else if (results.value == flag_led)
		{
			/* code */
			digitalWrite(blink,HIGH);
			delay(1000);
			digitalWrite(blink,LOW);
		}
		else if (results.value == flag_left)
		{
			/* code */
			left(200);
		}
		else if (results.value == flag_buzzer)
		{
			/* code */
			whistle();
			stop();
		}
		else if (results.value == flag_right)
		{
			/* code */
			right(200);
		}
		else if (results.value == flag_spin_left)
		{
			/* code */
			spin_left(200);
		}
		else if (results.value == flag_back)
		{
			/* code */
			back(200);
		}
		else if (results.value == flag_spin_right)
		{
			/* code */
			spin_right(200);
		}
		else if (results.value == flag_plus)
		{
			/* code */
		}
		else if (results.value == flag_zero)
		{
			/* code */
		}
		else if (results.value == flag_minus)
		{
			/* code */
		}
		else if (results.value == flag_one)
		{
			/* code */
		}
		else if (results.value == flag_two)
		{
			/* code */
		}
		else if (results.value == flag_three)
		{
			/* code */
		}
		else if (results.value == flag_four)
		{
			/* code */
		}
		else if (results.value == flag_five)
		{
			/* code */
		}
		else if (results.value == flag_six)
		{
			/* code */
		}
		else if (results.value == flag_seven)
		{
			/* code */
		}
		else if (results.value == flag_eight)
		{
			/* code */
		}
		else if (results.value == flag_nine)
		{
			/* code */
		}
		else
		{
			/* code */
		}
		last = millis();
		irrecv.resume();
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
}
// void run(int Speed)
// {
// 	digitalWrite(L_Motor_PIN1, HIGH);
// 	digitalWrite(L_Motor_PIN2, LOW);
// 	digitalWrite(R_Motor_PIN1, LOW);
// 	digitalWrite(R_Motor_PIN2, HIGH);
// 	analogWrite(L_Motor_PIN1, Speed);
// 	analogWrite(L_Motor_PIN2, 0);
// 	analogWrite(R_Motor_PIN1, 0);
// 	analogWrite(R_Motor_PIN2, Speed);
// }

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
	digitalWrite(R_Motor_PIN1, HIGH);
	digitalWrite(R_Motor_PIN2, LOW);
}
// void back(int Speed)
// {
// 	digitalWrite(L_Motor_PIN1, LOW);
// 	digitalWrite(L_Motor_PIN2, HIGH);
// 	analogWrite(L_Motor_PIN1, 0);
// 	analogWrite(L_Motor_PIN2, Speed);
// 	digitalWrite(R_Motor_PIN1, HIGH);
// 	digitalWrite(R_Motor_PIN2, LOW);
// 	analogWrite(R_Motor_PIN1, Speed);
// 	analogWrite(R_Motor_PIN2, 0);
// }

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
	digitalWrite(R_Motor_PIN1, LOW);
	digitalWrite(R_Motor_PIN2, HIGH);
}
// void left(int Speed)
// {
// 	digitalWrite(L_Motor_PIN1, LOW);
// 	digitalWrite(L_Motor_PIN2, LOW);
// 	analogWrite(L_Motor_PIN1, 0);
// 	analogWrite(L_Motor_PIN2, 0);
// 	digitalWrite(R_Motor_PIN1, LOW);
// 	digitalWrite(R_Motor_PIN2, HIGH);
// 	analogWrite(R_Motor_PIN1, 0);
// 	analogWrite(R_Motor_PIN2, Speed);
// }

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
	digitalWrite(R_Motor_PIN1, LOW);
	digitalWrite(R_Motor_PIN2, LOW);
}
// void right(int Speed)
// {
// 	digitalWrite(L_Motor_PIN1, HIGH);
// 	digitalWrite(L_Motor_PIN2, LOW);
// 	analogWrite(L_Motor_PIN1, Speed);
// 	analogWrite(L_Motor_PIN2, 0);
// 	digitalWrite(R_Motor_PIN1, LOW);
// 	digitalWrite(R_Motor_PIN2, LOW);
// 	analogWrite(R_Motor_PIN1, 0);
// 	analogWrite(R_Motor_PIN2, 0);
// }

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
	digitalWrite(R_Motor_PIN1, LOW);
	digitalWrite(R_Motor_PIN2, HIGH);
}
// void spin_left(int Speed)
// {
// 	digitalWrite(L_Motor_PIN1, LOW);
// 	digitalWrite(L_Motor_PIN2, HIGH);
// 	analogWrite(L_Motor_PIN1, 0);
// 	analogWrite(L_Motor_PIN2, Speed);
// 	digitalWrite(R_Motor_PIN1, LOW);
// 	digitalWrite(R_Motor_PIN2, HIGH);
// 	analogWrite(R_Motor_PIN1, 0);
// 	analogWrite(R_Motor_PIN2, Speed);
// }

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
	digitalWrite(R_Motor_PIN1, HIGH);
	digitalWrite(R_Motor_PIN2, LOW);
}
// void spin_right(int Speed)
// {
// 	digitalWrite(L_Motor_PIN1, HIGH);
// 	digitalWrite(L_Motor_PIN2, LOW);
// 	analogWrite(L_Motor_PIN1, Speed);
// 	analogWrite(L_Motor_PIN2, 0);
// 	digitalWrite(R_Motor_PIN1, HIGH);
// 	digitalWrite(R_Motor_PIN2, LOW);
// 	analogWrite(R_Motor_PIN1, Speed);
// 	analogWrite(R_Motor_PIN2, 0);
// }

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
	digitalWrite(R_Motor_PIN1, LOW);
	digitalWrite(R_Motor_PIN2, LOW);
}
// void stop()
// {
// 	digitalWrite(L_Motor_PIN1, LOW);
// 	digitalWrite(L_Motor_PIN2, LOW);
// 	analogWrite(L_Motor_PIN1, 0);
// 	analogWrite(L_Motor_PIN2, 0);
// 	digitalWrite(R_Motor_PIN1, LOW);
// 	digitalWrite(R_Motor_PIN2, LOW);
// 	analogWrite(R_Motor_PIN1, 0);
// 	analogWrite(R_Motor_PIN2, 0);
// }

void dump(decode_results *results)
{
	int count = results->rawlen;
	if (results->decode_type == UNKNOWN)
	{
		//Serial.println("Could not decode message");
		stop();
	}
}