
// -------------------------------------------------------------
// Mett: настройки моря
// заготовки на разные типы волнения:
// штиль, легкий бриз, бриз, умеренный бриз, сильный бриз, шторм
// -------------------------------------------------------------

string WhrGetSeaPresetFromWind(float fWind)
{
	string sPreset = "calm";
	if(fWind > 4.0) sPreset = "light_breeze";
	if(fWind > 7.0) sPreset = "breeze";
	if(fWind > 10.0) sPreset = "moderate_breeze";
	if(fWind > 13.0) sPreset = "strong_breeze";
	if(CheckAttribute(&WeatherParams, "Storm") && sti(WeatherParams.Storm) == 1) sPreset = "storm";
	return sPreset;
}

void WhrSetSeaPreset(int iCurWeatherNum, string sPreset)
{
	ref Whr = &Weathers[iCurWeatherNum];
	Sea.MaxSeaDistance = 2000.0
	/* Whr.Sea2.Reflection = 0.8;
    Whr.Sea2.Transparency = 0.3;
    Whr.Sea2.Frenel = 0.3;
    Whr.Sea2.Attenuation = 0.3;
    Whr.Sea2.WaterColor = argb(0, 10, 30, 50);
    Whr.Sea2.SkyColor = argb(0, 255, 255, 255);
    Whr.Sea2.BumpScale = 0.075; //ћ?Ћ »? ¬ќЋЌџ */

	switch(sPreset)
	{
			case "calm": //штиль
				Whr.Sea2.Amp1 = 0.5;//амплитуда 1 волны
				Whr.Sea2.AnimSpeed1 = 0.1; //скорость анимации
				Whr.Sea2.Scale1 = 1.5; //размеры волны
				Whr.Sea2.MoveSpeed1 = "0.0, 0.0, 0.5"; //скорость движения

				Whr.Sea2.Amp2 = 1.25;
				Whr.Sea2.AnimSpeed2 = 0.2;
				Whr.Sea2.Scale2 = 2.0;
				Whr.Sea2.MoveSpeed2 = "-0.5 0.0, 0.0";
				
				Whr.Sea2.Amp3 = 40.0
				Whr.Sea2.AnimSpeed3 = 4.0;
				Whr.Sea2.Scale3 = 0.12;
				Whr.Sea2.MoveSpeed3 = "8.0, 0.0, 0.0";
				
				Whr.Sea2.BumpScale = 0.075; //Ю?О†ї? ђЭОНЯ
				Whr.Sea2.PosShift = 1.75;//остроконечность волн
				Sea.Sea2.LodScale = 0.5;
	                        Sea.Sea2.GridStep = 0.05;

				Whr.Sea2.FoamK = 0.5;//яркость пены по высоте 0.1 - пена §рка§ с 10 метров 1.0 через метр после начала
				Whr.Sea2.FoamV = 1.5;////высота с которой начинаетс§ пена
				Whr.Sea2.FoamUV = 1.0; //тайлинг пены
				Whr.Sea2.FoamTexDisturb = 0.7;//сдвиг по нормали. х.з. что это надо поюзать. значение от 0.0 до 1.0

				Whr.Sea2.Reflection = 0.76;//0.8;
				Whr.Sea2.Transparency = 0.15;//0.6;
				Whr.Sea2.Frenel = 0.3;//0.6;
				Whr.Sea2.Attenuation = 0.3;//0.2;
				Whr.Sea2.WaterColor = argb(0, 10, 55, 40);
			break;

			case "light_breeze": //легкий бриз
				Whr.Sea2.Amp1 = 2.0;//амплитуда 1 волны
				Whr.Sea2.AnimSpeed1 = 1.0; //скорость анимации
				Whr.Sea2.Scale1 = 1.25; //размеры волны
				Whr.Sea2.MoveSpeed1 = "1.5, 0.0, 1.5"; //скорость движени§

				Whr.Sea2.Amp2 = 1.25;
				Whr.Sea2.AnimSpeed2 = 1.25;
				Whr.Sea2.Scale2 = 2.0;
				Whr.Sea2.MoveSpeed2 = "-1.5, 0.0, -1.5";

				Whr.Sea2.BumpScale = 0.075; //Ю?О†ї? ђЭОНЯ
				Whr.Sea2.PosShift = 1.75;//остроконечность волн
				Sea.Sea2.LodScale = 0.5;
	                        Sea.Sea2.GridStep = 0.05;

				Whr.Sea2.FoamK = 0.5;//§ркость пены по высоте 0.1 - пена §рка§ с 10 метров 1.0 через метр после начала
				Whr.Sea2.FoamV = 1.75;////высота с которой начинаетс§ пена
				Whr.Sea2.FoamUV = 1.0; //тайлинг пены
				Whr.Sea2.FoamTexDisturb = 0.7;//сдвиг по нормали. х.з. что это надо поюзать. значение от 0.0 до 1.0

				Whr.Sea2.Reflection = 0.76;//0.8;
				Whr.Sea2.Transparency = 0.3;//0.6;
				Whr.Sea2.Frenel = 0.3;//0.6;
				Whr.Sea2.Attenuation = 0.3;//0.2;
				Whr.Sea2.WaterColor = argb(0, 10, 55, 40);
			break;

			case "breeze":	//бриз
				Whr.Sea2.Amp1 = 4.0;//амплитуда 1 волны
				Whr.Sea2.AnimSpeed1 = 1.25; //скорость анимации
				Whr.Sea2.Scale1 = 0.6; //размеры волны
				Whr.Sea2.MoveSpeed1 = "0.0, 0.0, 2.0"; //скорость движени§

				Whr.Sea2.Amp2 = 2.0;
				Whr.Sea2.AnimSpeed2 = 2.0;
				Whr.Sea2.Scale2 = 1.5;
				Whr.Sea2.MoveSpeed2 = "-2.0, 0.0, 0.0";

				Whr.Sea2.BumpScale = 0.075; //Ю?О†ї? ђЭОНЯ
				Whr.Sea2.PosShift = 1.75;//остроконечность волн
				Sea.Sea2.LodScale = 0.5;
	                        Sea.Sea2.GridStep = 0.05;

				Whr.Sea2.FoamK = 0.15;//§ркость пены по высоте 0.1 - пена §рка§ с 10 метров 1.0 через метр после начала
				Whr.Sea2.FoamV = 3.0;//высота с которой начинаетс§ пена
				Whr.Sea2.FoamUV = 0.65; //тайлинг пены
				Whr.Sea2.FoamTexDisturb = 0.7;//сдвиг по нормали. х.з. что это надо поюзать. значение от 0.0 до 1.0

				Whr.Sea2.Reflection = 0.76;//0.8;
				Whr.Sea2.Transparency = 0.2;//0.6;
				Whr.Sea2.Frenel = 0.3;//0.6;
				Whr.Sea2.Attenuation = 0.3;//0.2;
				Whr.Sea2.WaterColor = argb(0, 10, 55, 40);
			break;

			case "moderate_breeze":	//бриз
				Whr.Sea2.Amp1 = 8.0; //амплитуда 1 волны
				Whr.Sea2.AnimSpeed1 = 1.5; //скорость анимации
				Whr.Sea2.Scale1 = 0.35; //размеры волны
				Whr.Sea2.MoveSpeed1 = "0.0, 0.0, 3.0"; //скорость движени§

				Whr.Sea2.Amp2 = 3.0;
				Whr.Sea2.AnimSpeed2 = 3.0;
				Whr.Sea2.Scale2 = 1.25;
				Whr.Sea2.MoveSpeed2 = "1.0, 0.0, 1.0";

				Whr.Sea2.BumpScale = 0.075; //Ю?О†ї? ђЭОНЯ
				Whr.Sea2.PosShift = 1.75; //остроконечность волн
				Sea.Sea2.LodScale = 0.5;
	                        Sea.Sea2.GridStep = 0.05;

				Whr.Sea2.FoamK = 0.3;//§ркость пены по высоте 0.1 - пена §рка§ с 10 метров 1.0 через метр после начала
				Whr.Sea2.FoamV = 6.0;//высота с которой начинаетс§ пена
				Whr.Sea2.FoamUV = 0.45; //тайлинг пены
				Whr.Sea2.FoamTexDisturb = 0.7;//сдвиг по нормали. х.з. что это надо поюзать. значение от 0.0 до 1.0

				Whr.Sea2.Reflection = 0.76;//0.8;
				Whr.Sea2.Transparency = 0.2;//0.6;
				Whr.Sea2.Frenel = 0.3;//0.6;
				Whr.Sea2.Attenuation = 0.3;//0.2;
				Whr.Sea2.WaterColor = argb(0, 10, 55, 35);
			break;

			case "strong_breeze"://ветрено
				Whr.Sea2.Amp1 = 16.0; //амплитуда 1 волны
				Whr.Sea2.AnimSpeed1 = 1.7; //скорость анимации
				Whr.Sea2.Scale1 = 0.20; //размеры волны
				Whr.Sea2.MoveSpeed1 = "0.0, 0.0, 5.0"; //скорость движени§

				Whr.Sea2.Amp2 = 4.0
				Whr.Sea2.AnimSpeed2 = 4.0;
				Whr.Sea2.Scale2 = 1.0;
				Whr.Sea2.MoveSpeed2 = "0.0, 0.0, -1.0";
				
				Whr.Sea2.Amp3 = 40.0
				Whr.Sea2.AnimSpeed3 = 4.0;
				Whr.Sea2.Scale3 = 0.12;
				Whr.Sea2.MoveSpeed3 = "8.0, 0.0, 0.0";

				Whr.Sea2.BumpScale = 0.075; //Ю?О†ї? ђЭОНЯ
				Whr.Sea2.PosShift = 1.75; //остроконечность волн
				Sea.Sea2.LodScale = 0.5;
	            Sea.Sea2.GridStep = 0.05;

				Whr.Sea2.FoamK = 0.25;//§ркость пены по высоте 0.1 - пена §рка§ с 10 метров 1.0 через метр после начала
				Whr.Sea2.FoamV = 11.0;//высота с которой начинаетс§ пена
				Whr.Sea2.FoamUV = 0.30; //тайлинг пены
				Whr.Sea2.FoamTexDisturb = 0.7;//сдвиг по нормали. х.з. что это надо поюзать. значение от 0.0 до 1.0

				Whr.Sea2.Reflection = 1.25;//0.8;
				Whr.Sea2.Transparency = 0.2;//0.6;
				Whr.Sea2.Frenel = 0.4;//0.6;
				Whr.Sea2.Attenuation = 0.25;//0.2;
				
				Whr.Sea2.WaterColor = argb(0, 10, 55, 35);
			break;

			case "storm"://шторм
				Whr.Sea2.Amp1 = 40.0; //амплитуда 1 волны
				Whr.Sea2.AnimSpeed1 = 2.0; //скорость анимации
				Whr.Sea2.Scale1 = 0.12; //размеры волны
				Whr.Sea2.MoveSpeed1 = "8.0, 0.0, 0.0"; //скорость движени§

				Whr.Sea2.Amp2 = 4.0;
				Whr.Sea2.AnimSpeed2 = 2.0;
				Whr.Sea2.Scale2 = 1.3;
				Whr.Sea2.MoveSpeed2 = "0.0, 0.0, -1.0";

				Whr.Sea2.BumpScale = 0.075; //Ю?О†ї? ђЭОНЯ
				Whr.Sea2.PosShift = 1.75; //остроконечность волн
				Sea.Sea2.LodScale = 0.5;
	                        Sea.Sea2.GridStep = 0.05;

				Whr.Sea2.FoamK = 0.10;//§ркость пены по высоте 0.1 - пена §рка§ с 10 метров 1.0 через метр после начала
				Whr.Sea2.FoamV = 24.0;//высота с которой начинаетс§ пена
				Whr.Sea2.FoamUV = 0.25; //тайлинг пены
				Whr.Sea2.FoamTexDisturb = 0.1;//сдвиг по нормали. х.з. что это надо поюзать. значение от 0.0 до 1.0

				Whr.Sea2.Reflection = 0.4;
				Whr.Sea2.Transparency = 0.15;
				Whr.Sea2.Frenel = 0.4;
				Whr.Sea2.Attenuation = 0.3;
				Whr.Sea2.WaterColor = argb(0, 20, 50, 40);
			break;
	}
	Log_TestInfo("WhrSetSeaPreset: выбран пресет " + sPreset);
}



