// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно, " + GetAddress_Form(NPChar) + "?"), "Опять вопросы, " + GetAddress_Form(NPChar) + "...", "Вопросы, вопросы... Может торговлей займёмся, " + GetAddress_Form(NPChar) + "?",
                          "Послушайте, ну сколько можно пустые разговоры вести?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Нет вопросов...", "Сейчас мне не о чем говорить"), "Эх, опять...",
                      "Да, действительно лучше торговаться...", "Хм, извини, торговец...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.PDM_PK_IshemKoltso == "IshemKoltso")	// Квест "Потерянное кольцо"
            {
                link.l1 = "Я разыскиваю кольцо, которое принадлежало... одному из моих знакомых. Довольно ценное кольцо. И это кольцо находится где-то в этом городе. Быть может, ты что-то слышал"+ NPCharSexPhrase(NPChar,"","а") +" о нём? Большой сапфир, в золотой оправе.";
                link.l1.go = "IshemKoltso";
            }
		break;

//******************** Квест "Потерянное кольцо" ******************
		case "IshemKoltso":
			int Phrase;
                Phrase = rand(4);
                if (Phrase == 0)
                {
					dialog.text = "Я кто по вашему, ювелир? Этот вопрос точно не ко мне.";
					link.l1 = "Извините.";
					link.l1.go = "exit";
				break;
				}
                if (Phrase == 1)
                {
					dialog.text = "У меня есть кольцо, но оно с " + LinkRandPhrase("рубином", "изумрудом", "алмазом") + ".";
					link.l1 = "Очень рад"+ GetSexPhrase("","а") +" за вас.";
					link.l1.go = "exit";
				break;
				}
				if (Phrase == 2)
                {
					dialog.text = "Я не продаю кольца.";
					link.l1 = "Извините.";
					link.l1.go = "exit";
				break;
				}
				if (Phrase == 3)
                {
					dialog.text = "У меня нет колец, извините.";
					link.l1 = "Ладно, поищу где-нибудь в другом месте.";
					link.l1.go = "exit";
				break;
				}
				if (Phrase == 4)
                {
					dialog.text = "Хммм... Вы говорите - сапфир? Да, я помню, что видел"+ NPCharSexPhrase(NPChar,"","а") +" кольцо, вроде того, о котором вы говорите. Оно у одной девки - может быть, вы даже знаете её - по крайней мере, большинству моряков она неплохо знакома. Её зовут Франческа. Я ещё никогда не встречал девчонки тупее, если честно. Какой-то солдат подарил ей это кольцо пару лет назад. Быть может он был ещё более глуп, чем она - поскольку это кольцо стоит неплохих денег. Да, это наверное то кольцо, которое вы ищете.";
					link.l1 = "Спасибо, "+npchar.name+", вы не представляете, как вы меня выручили. До встречи.";
					link.l1.go = "exit";

					AddQuestRecord("PDM_Poteryanoe_Koltso", "3");
					AddQuestUserData("PDM_Poteryanoe_Koltso", "sSex", GetSexPhrase("","а"));
					DeleteAttribute(pchar, "questTemp.PDM_PK_IshemKoltso");

					sld = GetCharacter(NPC_GenerateCharacter("PDM_PK_Francheska", "BaynesDaughterSTOK", "woman", "woman", 10, SPAIN, -1, false));
					sld.name = "Франческа";
					sld.lastname = "";
					sld.city = "SantoDomingo";
					sld.location	= "SantoDomingo_Brothel";
					sld.location.group = "goto";
					sld.location.locator = "goto3";
					sld.dialog.filename   = "Quest/PDM/Poteryanoe_Koltso.c";
					sld.dialog.currentnode   = "Francheska";
					LAi_SetCitizenType(sld);
					LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
					LAi_SetImmortal(sld, true);
				break;
				}
        break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

