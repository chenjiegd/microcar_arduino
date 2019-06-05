#include <IRremote.h>

int RECV_PIN = 2; //定义红外接收器的引脚为11
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
	// put your setup code here, to run once:
	Serial.begin(9600);
	irrecv.enableIRIn(); // 初始化红外接收器
}

void loop()
{
	// put your main code here, to run repeatedly:
	if (irrecv.decode(&results))
	{
		//FF00FF  	开关
		//FF807F  	前进
		//FF40BF  	灯
		//FF20DF  	左转
		//FFA05F  	喇叭
		//FF609F  	右转
		//FF10EF  	左旋
		//FF906F  	后退
		//FF50AF  	右旋
		//FF30CF  	加号
		//FFB04F  	0
		//FF708F  	减号
		//FF08F7  	1
		//FF8877  	2
		//FF48B7  	3
		//FF28D7  	4
		//FFA857  	5
		//FF6897  	6
		//FF18E7  	7
		//FF9867  	8
		//FF58A7  	9
		Serial.print("irCode: ");
		Serial.print(results.value, HEX); //以16进制换行输出接收代码
		// Serial.println();          //为了便于观看输出结果增加一个空行
		//results.value 是unsigned long型，头文件有介绍
		delay(100); //按键消抖
		Serial.print(", bits: ");
		Serial.println(results.bits); // 红外线码元位数
		irrecv.resume();			  // 接收下一个值
	}
}
