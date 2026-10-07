# ROOT 与高能物理数据分析基础
## 项目简介
本项目为科研训练作业，基于ROOT框架完成高能物理数据分析，模拟Z玻色子衰变 Z→μμ，完成直方图拟合、TTree数据读写、双μ子不变质量重建。

## 环境依赖
- WSL2 Ubuntu
- ROOT
- Git

## 文件说明
- `task3_gauss.C`：生成高斯随机事例，直方图+高斯拟合
- `task4_write_tree.C`：生成Z→μμ模拟数据，写入TTree
- `task4_read_tree.C`：读取ROOT文件TTree，绘制μ子动量分布
- `task5_invariant_mass.C`：读取TTree，计算双μ子不变质量，绘制不变质量谱并高斯拟合
- `.gitignore`：忽略不需要版本管理的文件

## 复现方法
激活ROOT环境：
```bash
conda activate root_env
```
运行示例：

root -l task3_gauss.C
root -l task4_write_tree.C
root -l task4_read_tree.C
root -l task5_invariant_mass.C
```
运行后生成 ROOT 数据文件与 png 图片。

## 结果

1. 任务 3：高斯分布拟合，验证随机数生成
2. 任务 4：TTree 读写，高能物理标准数据存储
3. 任务 5：双 μ 子不变质量重建，得到 Z 玻色子质量峰约 91.18 GeV

## 学习总结

掌握 ROOT 基础绘图、TTree 存储与读取、四动量不变质量计算，理解高能物理实验寻找共振峰的基本思路。