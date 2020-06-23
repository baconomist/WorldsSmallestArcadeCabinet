#pragma once

class SoundManager
{
public:
	static const int SPEAKER_PIN = 8;

	static void playLowBeep()
	{
		tone(SPEAKER_PIN, 270, 250);
	}

	static void playHighBeep()
	{
		tone(SPEAKER_PIN, 540, 250);
	}

	static void playStartMusic()
	{
		tone(SPEAKER_PIN, 440, 250);
		delay(250);
		tone(SPEAKER_PIN, 440, 250);
		delay(250);
		tone(SPEAKER_PIN, 220, 500);
		delay(500);
	}

	static void playBallHitBeep()
	{
		tone(SPEAKER_PIN, 660, 250);
	}

};