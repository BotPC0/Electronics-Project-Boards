import os


os.system('cp plantillaraul.call llamadaraul.call')
os.system('mv llamadaraul.call /var/spool/asterisk/outgoing')

GPIO.input(17)

