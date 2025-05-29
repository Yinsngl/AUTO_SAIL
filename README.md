# AUTO_SAIL
## 文件结构
```
    AUTO_SAIL
    |——Core 片上外设代码（由CubeMX生成）
    |   |——Inc
    |   |——Src
    |——Drivers 芯片核心驱动代码
    |——MDK-ARM
    |   |——AUTO_SAIL.uvprojx 项目工程文件
    |   |——AUTO_SAIL/AUTO_SAIL.hex 编译后生成此二进制文件，用于烧录
    |——User
    |   |——DRV8833 电机驱动
    |   |   |——Inc
    |   |   |——Src
    |   |——SG90 舵机驱动
    |   |   |——Inc
    |   |   |——Src
    |——AUTO_SAIL.ioc CubeMX工程文件
```
## 环境配置
    STM32CubeMX 6.13.0
    MDK-ARM 5.41.0
    STM32 ST-Link Utility 4.6.0.0

## 工具
    ST-Link Debugger
    CH340串口模块