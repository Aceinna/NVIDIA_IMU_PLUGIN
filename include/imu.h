/*******************************************************************************
Copyright 2021 ACEINNA, INC
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*******************************************************************************/

#include <iostream>
#include <dw/sensors/canbus/CAN.h>
#include <dw/sensors/imu/IMU.h>
#include <algorithm>
using namespace std;

class IMU
{
  public:

    virtual ~IMU(){};

    virtual bool init(string paramsString, dwCANMessage **messages, uint8_t *count) = 0;

    virtual bool isValidMessage(uint32_t message_id) = 0;

    virtual bool parseDataPacket(dwCANMessage packet, dwIMUFrame *IMUframe) = 0;

    virtual void getSensorResetMessage(dwCANMessage *packet) = 0;

  private:
};
