from gtts import gTTS
import os

lyrics = """ """
# 변수에 가사 작성

# TTS 엔진 설정
language = 'en'  
# 음성 변환에 사용할 언어를 설정함
slow = True
# 속도 설정 (False: 기본 속도)

tts = gTTS(text=lyrics, lang=language, slow=slow)
# tts 객체를 생성, gTTS 클래스 // 설정한 값을 인자로 전달해줌
tts.save('.mp3')
# tts 객체를 사용하여 음성을 .mp3로 저장하게 만들어줌

os.system('.mp3')
# 음성을 저장한 파일을 시스템 명령으로 실행함