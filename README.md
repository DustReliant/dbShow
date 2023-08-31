## 小工具：数据库表格查看器
### 简介
数据库表格查看器是一个基于 Qt 的简单应用程序，用于打开数据库文件（.db）并展示其中的表格内容。它提供了一个图形化界面，使用 QTabWidget 和 QTableWidget 来显示不同表格的数据。

### 代码环境
+ Qt 5.15.2

### 功能
打开数据库文件（.db 格式）。
在每个选项卡中展示不同表格的数据。
自动填充表格的内容，并适应内容长度。
将数据库文件拖放到可执行文件上打开(暂未支持，计划实现)。

### 使用方法
运行可执行文件 DatabaseTableViewer.exe。
点击 "打开文件" 按钮，选择一个数据库文件（.db 格式）。
在每个选项卡中，你将看到不同的表格名称，点击选项卡以查看表格的内容。
可以拖放一个数据库文件到可执行文件上来快速打开该数据库。

### 注意事项
本工具仅支持 SQLite 数据库文件（.db 格式）。
如果数据库文件损坏或格式不正确，可能会导致工具无法打开。
在查看大型数据库文件时，可能会有性能方面的限制。

### 版本修订记录

#### 0.1 基础版 ----2023.8.31
打开数据库文件（.db 格式）



### 联系信息
如有任何问题、反馈或建议，请联系：1619513467@qq.com