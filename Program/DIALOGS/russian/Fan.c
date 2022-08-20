
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		case "FirstMeet":
			dialog.text = "Вот это да, сам великий чемпион арены вышел мне навстречу! Можно мне следовать за тобой? Ну пожалуйста-пожалуйста!";
			link.l1 = "Так и быть... Идём.";
			link.l1.go = "exit";
			LAi_CharacterPlaySound(NPChar, "Fan_FirstMeet");
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_ActorFollowEverywhere(npchar, "", -1);
			Log_info("Самый преданный фанат чемпиона арены Скэм Геймс отныне следует за вами.");
		break;

		case "exit_2":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1", "", "", "", "OpenTheDoors", -1);
			npchar.LifeDay = 0;
			pchar.ScamDestroyed = true;
		break;

		case "exit_3":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_ActorFollowEverywhere(npchar, "", -1);
			chrDisableReloadToLocation = false;
			InterfaceStates.DisFastTravel = false;
		break;

		case "Scared":
			dialog.text = "Что мы здесь делаем?! Надо немедленно бежать отсюда!";
			link.l1 = "Хм, впервые вижу от тебя подобную реакцию. С чего бы вдруг?...";
			link.l1.go = "Scared_2";
			LAi_CharacterPlaySound(NPChar, "Fan_Scared");
		break;

		case "Scared_2":
			SpawnDeadGodSkulls();
			DialogExit();
		break;

		case "DeadGod":
		if (CheckCharacterItem(pchar,"skullAztec"))
		{
			dialog.text = "О, кого я вижу... Всё носишь мой подарочек?";
			link.l1 = "Миктлантекутли, у меня к тебе просьба. Выслушаешь?";
			link.l1.go = "DeadGod_2";
		}
		else
		{
			dialog.text = "Что это смертный делает в Жертвенном храме? Я требую объяснений!";
			link.l1 = "Уж не знаю, кто ты такой, но один твой вид уже меня пугает.";
			link.l1.go = "DeadGod_2";
		}
		break;

		case "DeadGod_2":
			if (CheckCharacterItem(pchar,"skullAztec"))
			{
				dialog.text = "Дай-ка я догадаюсь. Этот чудила с тобой? Избавиться от него?";
				link.l1 = "В точку. Поможешь?";
				link.l1.go = "DeadGod_3";
			}
			else
			{
				dialog.text = "Погоди-ка... Это кто ещё с тобой? Веет чем-то очень знакомым. Уж не тот ли придурок, которому я забавы ради даровал бессмертие, видя его полную никчёмность?";
				link.l1 = "Если ты поможешь мне от него избавиться, я сделаю что угодно.";
				link.l1.go = "DeadGod_3";
			}
		break;

		case "DeadGod_3":
			dialog.text = "Да раз плюнуть... Готово! Он больше никогда не вернётся сюда, на грешную землю. Ему пора.";
			link.l1 = "Чем мне отплатить тебе?";
			link.l1.go = "DeadGod_4";
			ref rChar = CharacterFromID("ScamCharacter");
			rChar.LifeDay = 0;
			ChangeCharacterAddressGroup(rChar, "none", "", "");
			Log_info("Самый преданный фанат чемпиона арены Скэм Геймс навсегда отстал от вас.");
		break;

		case "DeadGod_4":
			dialog.text = "Не безобразничать тут. В Теночтитлане вообще редко бродят живые помимо моих жрецов, поэтому я понаблюдаю за тем, что ты будешь тут делать.";
			link.l1 = "Я постараюсь ничем тебя не огорчать без необходимости. Прощай!";
			link.l1.go = "exit_2";
		break;

		case "CoolStory":
			string coolstory = "";
			switch (rand(20))
			{
				case 0:
					coolstory = "Нужно непременно добавить в энциклопедию список уникальных квестов и описание в каких городах их можно взять."
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_0");
				break;
				case 1:
					coolstory = "Предложение насчёт небольшого баланса кораблей. Сейчас бермудка корабля очень выгодна и в какой-то степени слишком хороша. Речь прежде всего о калибрах. Перескакивание с 24ф на 32ф это довольно сильно. Поэтому предложение немного сбалансировать этот аспект, чтобы это все ещё было отличным апгрейдом, но без такого апа, который есть сейчас. На примере любого корабля с 24ф. Сейчас бермудка апает с 24 до 32. Предложение сделать промежуточный калибр 28ф. Все ещё это будет хорошее усиление, но не такое сильное, как сейчас. Тоже самое сделать для других калибров, например вместо с 16 до 20 добавить промежуточный 18ф калибр. Уверен это окажет нормальное влияние на баланс."
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_1");
				break;
				case 2:
					coolstory = "Предложение убрать все тотемы, которые идут по квесту ТЕНО из продажи у торговцев и оставить их только, как квестовые на своих местах, то есть их нужно находить. Сделать это нужно, чтобы не было очевидных абузов в том виде, какой он есть сейчас, то есть покупать комплекты тотемов, Отдавать их офицерам и так можно сделать сколько угодно. К тому же убрав тотемы из продажи это уберёт путаницу у игроков с тем, что нельзя складывать один и тот же тотем в сундук иначе он просто пропадёт. Многие новички не знают этих деталей. И это ещё одна причина это сделать.";
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_2");
				break;
				case 3:
					coolstory = "Предложение добавить контрабандистам возможность заказывать себе нужные пушки. Цена будет дороже чем обычная. Будет также полезно тем кто играет за нацию пиратов.";
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_3");
				break;
				case 4:
					coolstory = "Я лично считаю скелеты в роли главных героев - провальная затея. Кодить и писать для них сюжет никто не хочет поэтому и смысла в них нет. Максимум можно было бы оставить одного подобного персонажа в качестве уникального гг, но только при условии, хотя-бы короткой сюжетки, а также уникальной модели персонажа в виде живого человека после перерождения.";
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_4");
				break;
				case 5:
					coolstory = "По хорошему нужно Пса вернуть в ГПК. Виспер взамен Пса дать другой  шип. ЖЧ нужно убирать из ГПК и оставить на будущее. Ей по типу ЛГ нужен свой отдельный квест. Для МКА будет свой квест с Чёрной Бородой. По крайней мере кое-кто об этом говорил. Хотя мне МКА тоже не нравится. Тем более я видел некоторые модели МКА, которые есть намного лучше. Жаль только их текстурить нужно и тд.";
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_5");
				break;
				case 6:
					coolstory = "Слишком много кораблей в паке. Хрен с ними с плохими моделями. Многие можно заменить. Но многие корабли просто ненужны. Они просто банально ни о чем. Зачем в игру нужно добавлять 10 видов шлюпов ненужных, когда будет три нормальных и адекватно сбалансированных?";
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_6");
				break;
				case 7:
					coolstory = "Решение с бесполезностью офицеров в лейте простое: 1. Сделать некоторые перки уникальными только для офицеров без возможности взять их для гг. Для этого можно ввести новые перки. 2. Сделать строгую привязку офицеров к своей специализации. Чтобы торгаш мог быть только торговцем без возможности быть абордажником. Так же и с другими должностями.";
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_7");
				break;
				case 8:
					coolstory = "Если хочеться помочь внедрить что-то новое, то гораздо полезнее вообще для всех внедрить какую-то новую анимацию ударов, чем добавлять в Корсары такую дичь с детьми. Насмотрелись уже на этих детей в Скайриме. Смысла подобного в играх ноль особенно, когда они играют роль обычных болванчиков. А уж играть за подобный ужас, да ещё на Шторме - нет уж, спасибо!";
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_8");
				break;
				case 9:
					coolstory = "Вообще разделение по названиям не так просто сделать. Удачное решение, как сейчас - это когда названия некоторых кораблей разделены по нациям. То есть, английский галеон, испанский и так далее. А вот от названий по типу тяжёлый боевой флейт нужно, как-то избавляться. Корабли 1 класса можно разделить по рангам на линейные корабли в зависимости от количества пушек.";
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_9");
				break;
				case 10:
					coolstory = "Все это дичь все эти перекрасы, которым уже десятки лет. Без новых моделей ничего не будет.";
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_10");
				break;
				case 11:
					coolstory = "Вся проблема в том, что невозможка интересна именно в морском бою. Реально интересно воевать. Но вот в бою на суше порой очень душит. Кто-то давно предлагал, чтобы можно было разделить сложность на два ползунка. Сложность на суше и в море. Тогда можно спокойно было-бы выставлять невозможку для морских сражений и к примеру сложность поменьше для сухопутного боя. Тогда не было бы никаких претензий к душным боям на суше.";
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_11");
				break;
				case 12:
					coolstory = "Добавить Англии, Голландии и Испании свои уникальные корабли, как награду за прохождение национальной линейки. Немного несправедливо, что только у Франции есть свой Солей. Другим тоже можно подобрать подобные корабли. Сделать их не мега монстрами, но, чтобы каждый имел свою уникальность в характеристиках.";
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_12");
				break;
				case 13:
					coolstory = "Убрать бессмысленный слив квеста Орион. Я понимаю, что может так было сделано раньше в угоду того, чтобы игрок случайно набрёл на этот квест и тд. Но многие игроки даже не узнают про него так, как брать работу на сопровождение многие просто не захотят и соответственно могут никогда и не узнать даже про этот квест. Сделать простое решение - добавить тавернщику отдельный диалог про слухи и работу. Такое уже сделано во многих нормальных квестах.";
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_13");
				break;
				case 14:
					coolstory = "Немного странное, но обьяснимое предложение - убрать у скелетов пистолеты. Может это и не понравиться кому-то, так как все привыкли к скелетам с четырёхствольными пистолетами и прочему, но это объяснимо с точки зрения здравого смысла и даже по лору игры. У скелетов не может быть исправном оружия.";
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_14");
				break;
				case 15:
					coolstory = "Как минимум Бладу можно продлить сюжет потому, что у него его нет, зато у Виспер есть. Также Граммону, Паттерсону и Диего.";
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_15");
				break;
				case 16:
					coolstory = "Для начала всем ключевым персонажам прологи бы нормальные сделать. А думать про глобальную сюжетку это странно.";
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_16");
				break;
				case 17:
					coolstory = "Самое забавное, что даже на невозможно ближе к 30 рангу спокойно уничтожаются любые корабли. То есть даже на такой сложности гг все равно имба. Но все же сейчас у ии появились апгрейды + защита корпуса. Так просто 3 классом первый класс уже не пробьешь.";
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_17");
				break;
				case 18:
					coolstory = "Вообще с балансом кораблей есть конечно проблемы. То, что полно так себе моделей это понятно, но замена модели лишь сделает кораблики покрасивее визуально, но не сделает их играбельными. Особенно таким страдают корабли 6 и 5 классов всякие шхуны, шлюпы, люггеры, которые просто очень слабы на фоне своих конкурентов в классе. К примеру тяжёлый шлюп в 6 вообще тянет на 5 класс. Остальные на его фоне просто дно. Ну и проблема в балансе 1 и 2 классов. На мой взгляд их чересчур много в игре. Всем нравятся красивые бои между кучей военных кораблей, но пожалуй перебор. Идеальный баланс, чтобы 2 и 1 класс встречались редко и только в самых сильных эскадрах. Тогда и игроку будет мотивация пытаться найти и захватить такие корабли.";
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_18");
				break;
				case 19:
					coolstory = "Вообще странная тема за офицеров. Все равно к примеру торгаша никто не будет назначать абордагом из-за низких навыков. Поэтому все разговоры за их имбовость слегка надуманны. Квестовые офы на то и квестовые, что они универсалы и многих из них ещё нужно найти.";
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_19");
				break;
				case 20:
					coolstory = "Вообще неплохо было-бы распределить все текущие модели офов по нациям. Чтобы к примеру у пиратов были только модели внешности пиратов и матросов. А в национальных городах были офицеры в соответствующих мундирах. Просто сейчас все офицеры просто рандомны. Интересно можно ли им прописывать нацию, как пгг и гг?";
					LAi_CharacterPlaySound(NPChar, "Fan_CoolStory_20");
				break;
			}
			dialog.text = coolstory;
			link.l1 = "Поразительные истории ты рассказываешь, бро...!";
			link.l1.go = "exit_3";
		break;
	}
}

void SpawnDeadGodSkulls()
{
	ref sld = GetCharacter(NPC_GenerateCharacter("FakeDeadmansGod", "mictlantecuhtli", "skeleton", "man", 100, PIRATE, 0, true));
    FantomMakeCoolFighter(sld, 100, 100, 100, "toporAZ", "pistol5", 3000);
	GetCharacterPos(pchar, &locx, &locy, &locz);
	ChangeCharacterAddressGroup(sld, "Temple_skulls", "goto", "goto2");
	LAi_SetActorTypeNoGroup(sld);
	LAi_SetImmortal(sld,true);
	sld.name = "Миктлантекутли";
	sld.lastname = "";
	sld.dialog.filename = "Fan.c";
	sld.dialog.currentnode = "DeadGod";
	LAi_group_MoveCharacter(sld, "player");
	LAi_ActorDialog(sld, pchar, "", 4.0, 0);
}
