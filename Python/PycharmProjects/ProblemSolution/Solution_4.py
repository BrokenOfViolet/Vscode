# 要求：
# 给定两个字符串：str1,str2。输出将字符串 2 变为字符串 1 所需最少次数。
# 规定：
# 两个字符串长度不超过 20，第二个字符串长度不小于第一个字符串。答案输出示例如图


import re


str1 = input("请输入第一个字符串:")
str2 = input("请输入第二个字符串:")

pattern = str1
result = re.match(pattern=pattern, string=str2)
print(result)

# 这题不会