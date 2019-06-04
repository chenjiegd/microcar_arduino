// 五丝菜卷
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
int infrared;//红外避障状态

int infrared = A7;

int Echo = 3; // Echo回声脚
int Trig = 4; // Trig触发脚

int distance = 0;

void setup()
{
	// put your setup code here, to run once:
	Serial.begin(9600); // 初始化串口

	pinMode(L_Motor_PIN1, OUTPUT);
	pinMode(L_Motor_PIN2, OUTPUT);
	pinMode(R_Motor_PIN1, OUTPUT);
	pinMode(R_Motor_PIN2, OUTPUT);
	pinMode(buzzer, OUTPUT); //设置数字IO脚模式，OUTPUT为输出
	pinMode(blink, OUTPUT);
	pinMode(key, INPUT);	  //定义按键输入脚
	pinMode(infrared, INPUT); //定义红外避障接收脚

	//初始化超声波引脚
	pinMode(Echo, INPUT);  // 定义超声波输入脚
	pinMode(Trig, OUTPUT); // 定义超声波输出脚

	// pinMode(4, OUTPUT);
	// digitalWrite(4, 0); //4是颜色识别传感器探照灯所连接的引脚，
	//初始化颜色识别传感器的探照灯灭（需要用到颜色识别传感器的时候，这一句就不需要）
	digitalWrite(buzzer, LOW);
	digitalWrite(blink, LOW);
}

void loop()
{
	// put your main code here, to run repeatedly:
	// Car_run
	//run(255);
	// delay(3000);
	// run(50);
	// delay(3000);

	// Whistle
	// whistle();
	// digitalWrite(blink,HIGH);
	// delay(1000);
	// digitalWrite(buzzer, LOW);
	// digitalWrite(blink,LOW);
	// delay(1000);

	//Ultrasonic_avoid
	// keysacn();
	// while (1)
	// {
	// 	/* code */
	// 	distance_test(); //测量前方距离
	// 	if (distance < 50)
	// 	{
	// 		while (distance < 50)
	// 		{
	// 			/* code */
	// 			right(100);
	// 			delay(20);
	// 			stop();
	// 			distance_test(); //测量前方距离
	// 		}
	// 	}
	// 	else
	// 	{
	// 		/* code */
	// 		run(250); //无障碍物，前进
	// 	}
	// }

	//Infrared_avoid
	keysacn();
	while (1)
	{
		/* code */
		infrared = 
	}
	
}

/**
* Function       
* @author        wusicaijuan
* @date          2019.06.04
* @brief         测距
* @param[in1]    void
* @retval        void
* @par History   无
*/
void keysacn() //按键扫描
{
	int val;
	val = digitalRead(key);   //读取数字7 口电平值赋给val
	while (!digitalRead(key)) //当按键没被按下时，一直循环
	{
		val = digitalRead(key); //此句可省略，可让循环跑空
	}
	while (digitalRead(key)) //当按键被按下时
	{
		delay(10);				//延时10ms
		val = digitalRead(key); //读取数字7 口电平值赋给val
		if (val == HIGH)		//第二次判断按键是否被按下
		{
			digitalWrite(buzzer, HIGH);	//蜂鸣器响
			while (!digitalRead(key))	  //判断按键是否被松开
				digitalWrite(buzzer, LOW); //蜂鸣器停止
		}
		else
			digitalWrite(buzzer, LOW); //蜂鸣器停止
	}
}

/**
* Function       distance_test
* @author        wusicaijuan
* @date          2019.06.04
* @brief         测距
* @param[in1]    void
* @retval        void
* @par History   无
*/
void distance_test() // 量出前方距离
{
	digitalWrite(Trig, LOW); // 给触发脚低电平2μs
	delayMicroseconds(2);
	digitalWrite(Trig, HIGH); // 给触发脚高电平10μs，这里至少是10μs
	delayMicroseconds(10);
	digitalWrite(Trig, LOW);			   // 持续给触发脚低电
	float Fdistance = pulseIn(Echo, HIGH); // 读取高电平时间(单位：微秒)
	Fdistance = Fdistance / 58;			   //为什么除以58等于厘米，  Y米=（X秒*344）/2
	// X秒=（ 2*Y米）/344 ==》X秒=0.0058*Y米 ==》厘米=微秒/58
	Serial.print("Distance:"); //输出距离（单位：厘米）
	Serial.println(Fdistance); //显示距离
	distance = Fdistance;
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