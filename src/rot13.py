# import codecs
import os

absolute_path = os.path.dirname(os.path.abspath(__file__))

inn = absolute_path + '/source.txt'

fin = open(inn)

text = fin.read()

# decode = codecs.decode(text, 'rot_13')

# print(decode)

fin.close()


rot13 = str.maketrans(
    'ABCDEFGHIJKLMabcdefghijklmNOPQRSTUVWXYZnopqrstuvwxyz',
    'NOPQRSTUVWXYZnopqrstuvwxyzABCDEFGHIJKLMabcdefghijklm')
out = text.translate(rot13)

print(out)
