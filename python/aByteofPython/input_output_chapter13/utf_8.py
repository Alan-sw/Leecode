# _*_ coding:utf-8 _*_
#the upper line is very important, see https://www.python.org/dev/peps/pep-0263.html
import io

f = io.open("abc.txt", "wt", encoding = "utf-8")
f.write(u"出来混，迟早是要还的")
f.close()

text = io.open("abc.txt", encoding = "utf-8").read()
print text
