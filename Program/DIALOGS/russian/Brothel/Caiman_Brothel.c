// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы, молодой человек?", "Чего ты хочешь, красавчик? Ну хоть задай его."), "Опять вопросы?", "Хи-хи, третий раз на дню одно и то же - вопросы...",
                          "Хм, может ты выберешь какую-нибудь красотку себе? А то у меня уже складывается в отношении тебя вполне определённое мнение...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал...", "Хм, да ничего..."), "Не могу... Нет вопросов...",
                      "Да уж, действительно в третий раз... Извини.", "Не сейчас... В другой раз...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

