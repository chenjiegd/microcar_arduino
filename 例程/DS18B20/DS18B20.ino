#define wusicaijuan chenshuaiqi
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 8            // 定义DS18B20数据口连接arduino的8脚
OneWire oneWire(ONE_WIRE_BUS);    // 初始连接在单总线上的单总线设备
DallasTemperature sensors(&oneWire);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);             // 设置串口通信波特率
  sensors.begin();                // 初始库
}

void loop() {
  // put your main code here, to run repeatedly:
  sensors.requestTemperatures();  // 发送命令获取温度
  Serial.print("温度值：");          //串口打印温度值
  Serial.print(sensors.getTempCByIndex(0)); 
  Serial.println("℃");
  delay(10);
}
