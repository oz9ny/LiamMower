/*
 Liam - DIY Robot Lawn Mower

 Battery Library

 ======================
  Licensed under GPLv3
 ======================
*/

#include <Arduino.h>

#ifndef _BATTERY_H_
#define _BATTERY_H_

// Voltages should be specified in mV (12.56 V = 12560 mV)
#define LIIONFULL       12200 //was 12560 Målt fyldt op 7/7-2019 12,312V
#define LIIONEMPTY      10400
#define NIMHFULL        14500
#define NIMHEMPTY       11500
#define LEADACIDFULL    17000 //was 13300
#define LEADACIDEMPTY   16000 //was 10500
// #define LEADACIDFULL    13300
// #define LEADACIDEMPTY   9500

// Running average sample size
#define FILTER        40

// Voltage divider factor x10 to avoid decimal ( 4 = 40)
#define VOLTDIVATOR   42


class BATTERY {
  public:
    BATTERY(int type, int sensepin, int dockpin);

    int getBatteryType();

    void setFullyChargedLevel(int level);
    int getFullyChargedLevel();

    void setDepletedLevel(int level);
    int getDepletedLevel();

    bool mustCharge();
    bool isBeingCharged();
    bool isFullyCharged();

    int getVoltage();
    void resetVoltage();
    void updateVoltage();
    word readBatteryAndCalcValue();

  private:
    int batType;
    int batSensePin;
    int batDockPin;
    int fullyChargedLevel;
    int depletedLevel;
    word averageVoltage;
};

#endif /* _BATTERY_H_ */
