import time
import os

from pocketsphinx import DefaultConfig, Decoder, get_model_path, get_data_path

dia=time.strftime("/%Y/%m/%d")

model_path = get_model_path()
data_path = "/var/spool/asterisk/rec" + dia
# data_path1 = get_data_path()
# print(data_path1)
print(data_path)

# Create a decoder with a certain model
config = DefaultConfig()
config.set_string('-hmm', os.path.join(model_path, 'en-us'))
config.set_string('-lm', os.path.join(model_path, 'en-us.lm.bin'))
config.set_string('-dict', os.path.join(model_path, 'cmudict-en-us.dict'))
decoder = Decoder(config)

# Decode streaming data
decode(os.path.join(data_path, 'internal-4001-4002-1.wav'), 2048)
