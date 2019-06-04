// 五丝菜卷
#define ON 1  //使能LED
#define OFF 0 //禁止LED

//定义电机的引脚
#define L_Motor_PIN1 11
#define L_Motor_PIN2 10
#define R_Motor_PIN1 9
#define R_Motor_PIN2 6

uint8_t i;
int buzzer = 12; //设置控制蜂鸣器的引脚
int blink = 13;

void setup()
{
	// put your setup code here, to run once:
	pinMode(L_Motor_PIN1, OUTPUT);
	pinMode(L_Motor_PIN2, OUTPUT);
	pinMode(R_Motor_PIN1, OUTPUT);
	pinMode(R_Motor_PIN2, OUTPUT);
	pinMode(buzzer, OUTPUT); //设置数字IO脚模式，OUTPUT为输出
	pinMode(blink,OUTPUT);
	// pinMode(4, OUTPUT);
	// digitalWrite(4, 0); //4是颜色识别传感器探照灯所连接的引脚，
	//初始化颜色识别传感器的探照灯灭（需要用到颜色识别传感器的时候，这一句就不需要）
	digitalWrite(buzzer, LOW);
	digitalWrite(blink,LOW);
}

void loop()
{
	// put your main code here, to run repeatedly:
	// run(255);
	// delay(3000);
	// run(50);
	// delay(3000);

	// whistle();
	// digitalWrite(blink,HIGH);
	// delay(1000);
	// digitalWrite(buzzer, LOW);
	// digitalWrite(blink,LOW);
	// delay(1000);
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
	analogWrite(L_Motor_PIN1, Speed);
	analogWrite(L_Motor_PIN2, 0);
	digitalWrite(R_Motor_PIN1, LOW);
	digitalWrite(R_Motor_PIN2, HIGH);
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
