String.prototype.replaceAll = function(s1,s2){
	return this.replace(new RegExp(s1,"gm"),s2); 
}
function QueryString()
	 {
		 var name,value,i;
		 var str=location.href;
		 var num=str.indexOf("?")
		 str=str.substr(num+1);
		 str=str.replaceAll("%20","");
		 var arrtmp=str.split("&");
		 for(i=0;i < arrtmp.length;i++){
			 num=arrtmp[i].indexOf("=");
			 if(num>0){
				 name=arrtmp[i].substring(0,num).replace("?","");
				 value=arrtmp[i].substr(num+1);
				 this[name]=value;
				 }
				}
		}
var Request=new QueryString();
curLangName=Request["lang"];
langeBaseNum=judgeBase(curLangName);


function judgeBase(curLangName)
{
	var baseIndex=0;
	if(curLangName.indexOf("en_US") >=0)
	{	
		baseIndex=0;
	}
	else if(curLangName.indexOf("zh_TW")>=0)
	{
		baseIndex=10;
	}
	else if(curLangName.indexOf("zh_CN")>=0)
	{
		baseIndex=20;
	}
	else if(curLangName.indexOf("fr")>=0)
	{
		baseIndex=30;
	}
	else if(curLangName.indexOf("de")>=0)
	{
		baseIndex=40;
	}
	else if(curLangName.indexOf("it")>=0)
	{
		baseIndex=50;
	}
	else if(curLangName.indexOf('es')>=0)
	{
		baseIndex=60;
	}
	else if(curLangName.indexOf("ja")>=0)
	{
		baseIndex=70;
	}
	else if(curLangName.indexOf("br")>=0)
	{
		baseIndex=80;
	}
	else
	{
		baseIndex=0;
	}
	return baseIndex;
}
var g_dataArray=new Array();
//The Data List is£º
//en_US
g_dataArray[0]='Getting Started';
g_dataArray[1]='1.Click the profile drop-down box to select a profile';
g_dataArray[2]='';
g_dataArray[3]='';
g_dataArray[4]='2.Click {GS_commandbar_add} button to add video file(s)';
g_dataArray[5]='';
g_dataArray[6]='';
g_dataArray[7]='3.Click {GS_commandbar_start} button to start converting';
g_dataArray[8]='';
g_dataArray[9]='';

//zh_TW
g_dataArray[10]='使用精靈';
g_dataArray[11]='1.點擊預置方案下拉框選擇一個預置方案';
g_dataArray[12]='';
g_dataArray[13]='';
g_dataArray[14]='2.點擊 {GS_commandbar_add} 按鈕添加視頻檔';
g_dataArray[15]='';
g_dataArray[16]='';
g_dataArray[17]='3.單擊 {GS_commandbar_start} 按鈕開始轉換';
g_dataArray[18]='';
g_dataArray[19]='';

//zh_CN
g_dataArray[20]='使用向导';
g_dataArray[21]='1.点击预置方案下拉框选择一个预置方案';
g_dataArray[22]='';
g_dataArray[23]='';
g_dataArray[24]='2.点击 {GS_commandbar_add} 按钮添加文件';
g_dataArray[25]='';
g_dataArray[26]='';
g_dataArray[27]='3.点击 {GS_commandbar_start} 按钮开始转换';
g_dataArray[28]='';
g_dataArray[29]='';

//fr
g_dataArray[30]='Pour commencer';
g_dataArray[31]='1.Cliquez sur la liste déroulante &quot;Profil&quot; pour sélectionner un profil';
g_dataArray[32]='';
g_dataArray[33]='';
g_dataArray[34]='2.Cliquer sur le bouton {GS_commandbar_add} pour ajouter des fichiers vidéo';
g_dataArray[35]='';
g_dataArray[36]='';
g_dataArray[37]='3.Cliquer sur le bouton {GS_commandbar_start} pour démarrer la conversion';
g_dataArray[38]='';
g_dataArray[39]='';

//de
g_dataArray[40]='Anleitung';
g_dataArray[41]='1.Klicken Sie auf die Dropdown-Liste &quot;Profil&quot;, um ein Profil zu wählen';
g_dataArray[42]='';
g_dataArray[43]='';
g_dataArray[44]='2.Klicken Sie auf {GS_commandbar_add}, um Videodatei(en) hinzuzufügen';
g_dataArray[45]='';
g_dataArray[46]='';
g_dataArray[47]='3.Klicken Sie auf {GS_commandbar_start}, um die Konvertierung zu starten';
g_dataArray[48]='';
g_dataArray[49]='';

//it 
g_dataArray[50]='Iniziare';
g_dataArray[51]='1.Clicca la lista dei profili preimpostati per scegliere un profilo';
g_dataArray[52]='';
g_dataArray[53]='';
g_dataArray[54]='2.Clicca il pulsante {GS_commandbar_add} per aggiungere files video';
g_dataArray[55]='';
g_dataArray[56]='';
g_dataArray[57]='3.Clicca il pulsante {GS_commandbar_start} per avviare la conversione';
g_dataArray[58]='';
g_dataArray[59]='';

//es
g_dataArray[60]='Cómo Empezar';
g_dataArray[61]='1.Haga clic en el perfil predefinido desplegable para seleccionar un perfil predefinido';
g_dataArray[62]='';
g_dataArray[63]='';
g_dataArray[64]='2.Haga clic {GS_commandbar_add} para añadir archivo(s)';
g_dataArray[65]='';
g_dataArray[66]='';
g_dataArray[67]='3.Haga clic {GS_commandbar_start} para iniciar la conversión';
g_dataArray[68]='';
g_dataArray[69]='';

//ja
g_dataArray[70]='スタート';
g_dataArray[71]='1.プロフィールドロップダウン枠からプロフィールを選択してクリックする';
g_dataArray[72]='';
g_dataArray[73]='';
g_dataArray[74]='2.{GS_commandbar_add}ボタンをクリックし、ビデオファイルを添加';
g_dataArray[75]='';
g_dataArray[76]='';
g_dataArray[77]='3.{GS_commandbar_start}ボタンをクリックし、変換を開始します';
g_dataArray[78]='';
g_dataArray[79]='';

//br
g_dataArray[80]='Vamos começar';
g_dataArray[81]='1.Clique em &quot;Perfil&quot; na lista de drop-down para selecionar um perfil pre determinado';
g_dataArray[82]='';
g_dataArray[83]='';
g_dataArray[84]='2.Clique no botão {GS_commandbar_add} para adicionar arquivos';
g_dataArray[85]='';
g_dataArray[86]='';
g_dataArray[87]='3.Clique no botão {GS_commandbar_start} para iniciar a converter';
g_dataArray[88]='';
g_dataArray[89]='';