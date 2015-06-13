STM32-TEA-Encryption-Recorder
============
A STM32 encryption recorder that use Tiny Encryption Algorithm.

Users can record and play audio and save it to the SD card like ordinary recorder, but the audio file on the SD card can't be played in other device like PC.

![STM32-TEA-Encryption-Recorder](https://github.com/lincanbin/STM32-TEA-Encryption-Recorder/blob/master/Screenshots/start.jpg)

![record](https://github.com/lincanbin/STM32-TEA-Encryption-Recorder/blob/master/Screenshots/record.jpg)

![play](https://github.com/lincanbin/STM32-TEA-Encryption-Recorder/blob/master/Screenshots/play.jpg)

Requirements
------------
* STM32
* WMA audio decoder like VS10XX
* SD card read and write device
* The LCD screen( for debug only)

Test case
------------

The audio waveform before encryption: 

![before](https://github.com/lincanbin/STM32-TEA-Encryption-Recorder/blob/master/Screenshots/before.png)

The encrypted audio waveform: 

![after](https://github.com/lincanbin/STM32-TEA-Encryption-Recorder/blob/master/Screenshots/after.png)

License
------------
```
Copyright 2006-2015 Canbin Lin (lincanbin@hotmail.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
```