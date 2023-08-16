#ifndef COMMANDREGISTER_H
#define COMMANDREGISTER_H

#include <cstdint>

enum RegisterEnum : uint32_t
{
    // AISC ADC registers
    WRITE_ADC_SAMPLE_PERIOD_CFG_REG_32BIT = 0x00000001,    // 写：ADC采样周期配置寄存器
    WRITE_ADC_SAMPLE_CHANNEL_CFG_REG_8X32BIT = 0x00000002, // 写：ADC每个周期内32个采样点采样通道号配置寄存器
    WRITE_ADC_ENABLE_REG_32BIT = 0x00000003,               // 写：ADC使能寄存器
    WRITE_ADC_OFFSETCAL_ENABLE_REG_32BIT = 0x00000004,     // 写：ADC offsetcal 使能寄存器
    WRITE_ADC_ACQ_TIME_CFG_REG_32BIT = 0x00000005,         // 写：ADC ACQ time 配置寄存器
    READ_ADC_SAMPLE_PERIOD_CFG_REG_32BIT = 0x80000001,     // 读：ADC采样周期状态寄存器
    READ_ADC_SAMPLE_CHANNEL_CFG_REG_8X32BIT = 0x80000002,  // 读：ADC每个周期内32个采样点采样通道号状态寄存器
    READ_ADC_ENABLE_REG_32BIT = 0x80000003,                // 读：ADC使能状态寄存器
    READ_ADC_ACQ_TIME_CFG_REG_32BIT = 0x80000005,          // 读：ADC ACQ time 状态寄存器

    // ASIC CONTROL registers
    WRITE_ASIC_CTRL_REG_32BIT = 0x01000001,                     // 写：ASIC控制寄存器
    WRITE_ASIC_POWER_CTRL_REG_32BIT = 0x01000002,               // 写：ASIC POWER 控制寄存器
    WRITE_ASIC_VCM_EN_CTRL_REG_32BIT = 0x01000003,              // 写：ASIC VCM_EN 控制寄存器
    WRITE_ASIC_FC_VCOM_EN_CTRL_REG_32BIT = 0x01000004,          // 写：ASIC FC_VCOM_EN 控制寄存器
    WRITE_ASIC_CHANNEL_STATE_CFG_REG_32X32BIT = 0x01000005,     // 写：ASIC 1024个通道开关状态配置寄存器
    WRITE_ASIC_SINGLE_CHANNEL_STATE_CFG_REG_32BIT = 0x01000006, // 写：ASIC 单个通道开关状态配置寄存器
    WRITE_ASIC_UNBLOCK_CHANNEL_CFG_REG_32BIT = 0x01000007,      // 写：ASIC unblock通道号配置寄存器
    READ_ASIC_STATUS_REG_32BIT = 0x81000001,                    // 读：ASIC状态寄存器

    // ASIC cooling control registers
    WRITE_HEATER_VOLTAGE_CFG_REG_32BIT = 0x02000001,   // 加热器电压配置寄存器, 写
    WRITE_ASIC_TEMP_SET_REG_32BIT = 0x03000001,        // ASIC 温度设定寄存器, 写
    READ_ASIC_TEMP_SENSOR_REG_32BIT = 0x83000001,      // ASIC 温度传感器返回值, 读
    READ_HEATER_VOLTAGE_STATUS_REG_32BIT = 0x82000001, // 加热器电压状态寄存器, 读

    // ... (其他寄存器)

    // LED control registers
    READ_LED_CURRENT_VALUE_REG_32BIT = 0x84000001,  // LED 电流值寄存器 32BIT[]
    WRITE_LED_OUTPUT_STATUS_REG_32BIT = 0x06000001, // LED 输出状态, 写
    READ_LED_STATUS_REG_32BIT = 0x86000001         // LED 状态寄存器, 读
};


#endif // COMMANDREGISTER_H
