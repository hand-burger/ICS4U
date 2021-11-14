import codecs
import os

absolute_path = os.path.dirname(os.path.abspath(__file__))
inn = absolute_path + '/source.txt'
fin = open(inn)
text = fin.read()

# This is so easy in python, 3 lines . . .

decode = codecs.decode(text, 'rot_13')

print(decode)

fin.close()
