# 任意精度物理模拟计算（力学）

本项目探索了**任意精度**的物理模拟方法，旨在实现比传统的 **Euler** 方法和 **Verlet** 方法更高精度的运动学模拟。

## 💡 项目简介

本程序可用于研究或验证任意精度数值计算在力学模拟中的效果。
核心目标是减少数值误差累积，实现对经典物理系统的高精度求解。

## 🧩 系统和依赖要求

目前应当只有 macOS 和 Linux 系统可以使用本项目，Windows 用户可在适当修改 [./Makefile](/Makefile) 之后再尝试使用。

请先确保您的系统中已安装 [make](https://en.wikipedia.org/wiki/Make_(software)) 。

## 🚀 运行程序的方法

在命令行进入您希望放置项目的目录，然后运行：
```
git clone https://github.com/NoPhyNoLife/Percise_Physic_Simulation.git
```
进入项目根目录后，构建项目：
```
make
```
构建过程中可能会出现许多 warning ，一般可以忽略。

在这之后，运行模拟程序：
```
make run
```
这会自动执行预设的模拟示例。

若在第一次构建中出现错误，请先排查问题后执行以下命令：
```
make clean
```
然后重新运行 `make` 进行构建。

如果问题仍无法解决，请在本项目的 [GitHub Issues](https://github.com/NoPhyNoLife/Percise_Physic_Simulation/issues) 中提交反馈。

---

- [ ] 若想修改给定的条件/模拟的方程？（README not finished yet）

