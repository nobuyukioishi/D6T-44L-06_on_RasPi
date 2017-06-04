Omron D6T-44L-06 test application
=================================

Testing the sensor on the Raspberry Pi.
You can check if the sensor Omron D6T-44L-06 is working properly with your Raspberry Pi.

This program generates a CSV file named 'Test.csv' including each of the 4x4 grid's temperature in celsius scale and timestamp corresponding to it.

CSV sample
----------

```CSV
2017/5/22 16:22:50.52441,30.3,29.7,27.6,29.6,27.3,27.4,27.4,27.5,27.3,27.3,27.4,27.7,31.2,30.4,27.5,30.3
2017/5/22 16:22:51.58987,30.4,29.7,27.8,29.7,27.4,27.6,27.5,27.6,27.3,27.4,27.4,27.6,30.0,28.6,27.4,30.3
2017/5/22 16:22:52.65286,30.4,29.8,27.8,29.3,27.4,27.6,27.6,27.4,27.3,27.4,27.4,27.8,27.3,27.7,27.7,29.3
2017/5/22 16:22:53.70892,30.4,29.8,27.8,29.2,27.4,27.6,27.5,27.4,27.3,27.3,27.5,27.4,27.3,27.2,27.2,27.7
2017/5/22 16:22:54.77558,30.3,29.7,27.7,29.2,27.4,27.5,27.4,27.4,27.2,27.3,27.4,27.2,27.3,27.1,27.0,27.5
2017/5/22 16:22:55.83788,30.3,29.7,27.7,29.2,27.3,27.5,27.4,27.3,27.2,27.3,27.4,27.3,27.2,27.1,27.1,27.5
...

```

How to Use
----------

After cloning this repository, you can simple compile and run this code by doing as follows.

```bash
cd src
make
```

Disclaimer
----------

I mainly reused a code by [Krisjanis Rijnieks](https://github.com/kr15h)'s https://github.com/kr15h/omron-d6t-44l-06-rpi-of-test .
I just modified some code in main.cpp file in order to output the sensor's data into CSV file.

I recommend you to refer his repository when my code doesn't work properly or if you have any question.
