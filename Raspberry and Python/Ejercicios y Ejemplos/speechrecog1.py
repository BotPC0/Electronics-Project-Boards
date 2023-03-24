import time
import os

from pocketsphinx import AudioFile, get_model_path, get_data_path

dia = time.strftime("/%Y/%m/%d")

model_path = get_model_path()
data_path = "/var/spool/asterisk/rec" + dia
# data_path1 = get_data_path()
# print(data_path1)
print(data_path)

# Set Configuration
config = {
	'verbose': False,
	'audio_file': os.path.join(data_path, 'internal-4001-4002-1.wav'),
	'buffer_size': 2048,
	'no_search': False,
	'full_utt': False,
	#'hmm': os.path.join(model_path, 'en-us'),
	#'lm': os.path.join(model_path, 'en-us.lm.bin'),
	#'dict': os.path.join(model_path, 'cmudict-en-us.dict')
}

# Process Audio
audio = AudioFile(**config)
for phrase in audio:
	print(phrase)
	os.remove(os.path.join(data_path, 'internal-4001-4002-1.wav'))
