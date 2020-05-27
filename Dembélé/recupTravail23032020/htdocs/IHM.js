var identifiant;
var trId;
var dateEnregistrement;
var color= "#410202";
var colortab='#c19b9b';

   $(function() {
    $('#tableau').on('click','tr', ClicTableau);
    $('#nouveau').on('click',Nouveau);
    $('#modifier').on('click', Modifier);
    $('#supprimer').on('click', Supprimer);
    $('#geo').on('click', BoutonGeolocaliser); 
    $("#bLux").on('click', mesureLux);
    $("#save").on('click', BoutonEnregistrer);
    $("#modeRevue").on('click', ChangerMode);
    $("#bShutdown").on('click', stopSystem);
    $("#bAllDelete").on('click', allDelete);
    $("#valider").on('click',majCouleur);
    $("#buttoncolor").on('click',colordefault);
    $("#envoibdd").on('click',envoimailbdd);
    
});


$('#chargement').hide();
$('#btnRed').hide();
$('#geoFix').hide();


var tabPhoto = new Array();
var lol=0;
var tab= new Array(); 
function genererTableau(data){
            $("#tableau").empty();
   $('#page1 .ui-btn').css('background-color',colortab);
   $('#page1 .ui-body-inherit').css('background-color',colortab);
   $('#page1 .ui-responsive').css("background-color", colortab); 
   $('#page1 tr').css("background-color",colortab);
   $(this).closest("#page1 tr").css("color",colortab);
            var tableau = "<table data-role='table' id='table' class='ui-responsive'     ><thead ><tr class='ui-grid-c'>";

                    tableau += "<th class='entete ui-block-a' style='width: 10%'>ID</th>";//CLE = ALBEDO, ID,ULOR etc
                    tableau += "<th class='entete ui-block-b' style='width: 28%'>LAT.</th>";//CLE
                    tableau += "<th class='entete ui-block-c' style='width: 28%'>LONG.</th>";//CLE
                    tableau += "<th class='entete ui-block-d' style='width: 17%'>ALT.</th>";//CLE
                    tableau += "<th class='entete ui-block-d' style='width: 17%;float:right'>ULOR</th>";//CLE
                    console.log(data);

//début du code de maintien du valeur champ lors du rechargement de la page 

	$('#dheight').val(data[0].HEIGHT);
        $('#dlampadaire').val(data[0].STREETLIGHT);
	$('#dlampadaire').selectmenu('refresh') 
	$('#dULOR').val(data[0].ULOR + "%");
	$('#dULOR').selectmenu('refresh');
	$('#dAmpoule').val(data[0].LAMP); 
	$('#dAmpoule').selectmenu('refresh');
	$('#dPuissance').val(data[0].POWER); 
	$('#dAlbedo').val(data[0].ALBEDO); 
	$('#dAlbedo').selectmenu('refresh');
	$('#dTown').val(data[0].TOWN); 
	$('#dStreet').val(data[0].STREET); 
	$('#dNotes').val(data[0].NOTES) ; 
	$('#dLum').val(data[0].FLUX);

//fin du code de maintien du valeur champ lors du rechargement de la page 

            tableau += "</tr></thead><tbody>";
            for (var i=0; i<data.length; i++)
            {
                  
                tableau += "<tr class='ui-grid-c' id="+i+">";
                tableau += "<td class='ui-block-a remplissage' style='width: 10%'>"+data[i].ID+"</td>";
                tableau += "<td class='ui-block-b remplissage' style='width: 28%'>"+data[i].LATITUDE+"</td>";
                tableau += "<td class='ui-block-c remplissage' style='width: 28%'>"+data[i].LONGITUDE+"</td>";
                tableau += "<td class='ui-block-d remplissage' style='width: 17%'>"+data[i].ALTITUDE+"</td>"; 
                tableau += "<td class='ui-block-e remplissage' style='width: 17%;float:right'>"+data[i].ULOR+"</td>";

                tableau += "</tr>";
            }
               
       
            tableau += "</tbody></table>";
         


            $("#tableau").append(tableau);
            $('#page1 .ui-responsive').css("background-color", colortab);   
}
function majcolorp3(){
     $('.ui-btn').css('padding-left','0em');
    $('.ui-btn').css('padding-right','0em');
    $('.ui-btn').css('padding-top','0.5em');
    $('.ui-btn').css('padding-bottom','0.5em');
    $('.ui-btn').css('margin','0.5em'); 
    $('.ui-btn').css('margin-left','0.1em');     
    $('.ui-btn').css('margin-right','0.1em');     
    $('.ui-btn').css('min-height','1em');   
    $('.ui-btn').css('background-color',black);
    $('.ui-body-inherit').css('background-color',black);
}
function displayList(){
    $('.ui-btn').css('padding-left','0em');
    $('.ui-btn').css('padding-right','0em');
    $('.ui-btn').css('padding-top','0.5em');
    $('.ui-btn').css('padding-bottom','0.5em');
    $('.ui-btn').css('margin','0.5em'); 
    $('.ui-btn').css('margin-left','0.1em');     
    $('.ui-btn').css('margin-right','0.1em');     
    $('.ui-btn').css('min-height','1em');
    $('.ui-btn').css('background-color',colortab);
    $('.ui-body-inherit').css('background-color',colortab);

    $('#dLatitude').css('color','black');
    $('#dLongitude').css('color','black');
    $('#dAltitude').css('color','black');
    $('#dSatellite').css('color','black');
    $('#dNbrMesures').css('color','black');
    $('#dFix').css('color','black');    
    $('#dPrecision').css('color','black');   

    $('#dLatitude').css('font-size','1.4em');
    $('#dLongitude').css('font-size','1.4em');   
    $('#dAltitude').css('font-size','1.4em');   
    $('#dSatellite').css('font-size','1.4em');   
    $('#dNbrMesures').css('font-size','1.4em');   
    $('#dFix').css('font-size','1.4em');   
    $('#dPrecision').css('font-size','1.4em');   

 
    $('#dLatitude').css('text-shadow','0px 0px 0px');
    $('#dLongitude').css('text-shadow','0px 0px 0px');  
  
    $('#dLatitude').css('padding-top','0em');
    $('#dLongitude').css('padding-top','0em');  
    $('#dLatitude').css('padding-bottom','0em');
    $('#dLongitude').css('padding-bottom','0em');  
    $('#dLatitude').css('margin-top','0em');
    $('#dLongitude').css('margin-top','0em');
    $('#dLatitude').css('margin-left','0.1em');
    $('#dLongitude').css('margin-left','0.1em');
    $('#dLatitude').css('margin-bottom','0em');
    $('#dLongitude').css('margin-bottom','0em');     
    $('#dLatitude').css('border-top','0em');
    $('#dLongdisplayitude').css('border-top','0em');
    $('#dLatitude').css('border-bottom','0em');
    $('#dLongitude').css('border-bottom','0em');
    
    
    $.ajax({    
        type : 'GET',
        url : '/cgi-bin/listerEnregistrements.cgi',
        dataType : 'json',
        success : function (data) {
            tab = data.enregistrement;
            console.log("length =" + tab.length);
            genererTableau(tab);
        },
        error : function (result, status, erreur){

            alert(erreur + '///' + result);
        }
    });
};


function lampadairesProches(){
    $.ajax({    
        type : 'GET',
        url : '/cgi-bin/lampProches.cgi',
        dataType : 'json',
        success : function (data) {
            tab = data.enregistrement;
            genererTableau(tab);
        },
        error : function (result, status, erreur){

            alert(erreur + '///' + result);
        }
    });
};

function updateList()
{
    
}

function estLEnregistrement(element,index,array)
{
    if (element.ID==identifiant) {
        return true;
    }
    return false;
}

function BoutonEnregistrer()
{
	formData = new FormData();
        //formData.append('identifiant', identifiant);
	formData.append('latitude', $('#dLatitude').val()); 
    
//ajout des nouveaux champs

        formData.append('altitude', $('#dAltitude').val());
        formData.append('satellites', $('#dSatellites').val());
        formData.append('nbrMesures', $('#dNbrMesures').val());
        formData.append('fix', $('#dfix').val());
        formData.append('precision', $('#dPrecision').val());
        
	formData.append('longitude', $('#dLongitude').val()); 
	formData.append('typeLampadaire', $('#dlampadaire').val()); 
	formData.append('ulor', $('#dULOR').val()); 
	formData.append('typeAmpoule', $('#dAmpoule').val()); 
	formData.append('hauteur', $('#dheight').val());
	formData.append('puissance', $('#dPuissance').val()); 
	formData.append('albedo', $('#dAlbedo').val()); 
	formData.append('agglomeration', $('#dTown').val()); 
	formData.append('rue', $('#dStreet').val()); 
	formData.append('notes', $('#dNotes').val() ); 
	formData.append('fluxlum', $('#dLum').val());
	formData.append('nbImage', tabPhoto.length);
        formData.append('date', dateEnregistrement);
        //envoi(identifiant); envoi photo non traité
    	if($('#nouveau').val() === 'Annuler')
    	{
            var request = new XMLHttpRequest();
            request.onreadystatechange = function() {
                if (this.readyState === 4 && this.status === 200) {
                    //console.log(this.responseText);
                    var myArr = JSON.parse(this.responseText);
                    var buffer = tab.reverse();
                    tab.push(myArr);
                    buffer = tab.reverse();
                    genererTableau(tab);
                    $('#dLatitude').val('');
                    $('#dLongitude').val('');
                    $('#dAltitude').val('');
                    $('#dSatellite').val('');
                    $('#dFix').val('');
                    $('#dPrecision').val('');
                    $('#dNbrMesures').val('');

                }
            };
            
            request.open("POST", "/cgi-bin/enregistrer.cgi");
            request.send(formData);
    	}
 
        if($('#modifier').val() == 'Annuler')
    	{
            formData.append('ID', identifiant);            
            var request = new XMLHttpRequest();
            request.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    //var indice = tab.findIndex(estLEnregistrement);
                    var indice = trId;
                    tab[indice].LATITUDE= $('#dLatitude').val(); 
                    tab[indice].LONGITUDE= $('#dLongitude').val(); 
                    
 //ajout des nouveaux champs
 
                    tab[indice].ALTITUDE= $('#dAltitude').val(); 
                    tab[indice].SATELLITES= $('#dSatellites').val(); 
                    tab[indice].NBRMESURES= $('#dNbrMesures').val(); 
                    tab[indice].FIX= $('#dfix').val(); 
                    tab[indice].PRECISION= $('#dPrecision').val(); 
 
       		    tab[indice].HEIGHT=$('#dheight').val();
                    tab[indice].POWER=$('#dPuissance').val();
                    tab[indice].TOWN=$('#dTown').val();
                    tab[indice].STREET=$('#dStreet').val();
                    tab[indice].NOTE=$('#dNotes').val();
                    tab[indice].FLUX=$('#dLum').val();
                    tab[indice].STREETLIGHT=$('#dlampadaire').val();
                    tab[indice].LAMP=$('#dAmpoule').val();
                    tab[indice].ALBEDO=$('#dAlbedo').val();
                    tab[indice].ULOR=($('#dULOR').val().split("%"))[0];
                    tab[indice].DATE=dateEnregistrement;
                    tab[indice].ID=identifiant;
                    genererTableau(tab);
                    $('#dLatitude').val('');
                    $('#dLongitude').val('');
                }
            };            
            request.open("POST", "/cgi-bin/modifier.cgi");
            request.send(formData);  
        }


            //$('#tab2').attr('class', 'ui-listview'); // cet �l�ment aura la classe ui-listview
            $('#tableau').attr('class', 'ui-grid-solo'); //On degrise le tableau

            $('#nouveau').prop('value', 'Nouveau');
            $('#nouveau').prop('disabled', false);
            $('#nouveau').button('refresh');

            $('#modifier').prop('value', 'Modifier');
            $('#modifier').prop('disabled', true);
            $('#modifier').button('refresh');
            griserChamps();
}

var sse = $.SSE("/cgi-bin/lampProches.cgi",{//sse.cgi", {

    onOpen: function(){
        console.log("Open"); 
    },
    onEnd: function(){
        console.log("End"); 
    },
    onError: function(e){
        alert("Connexion impossible au mode revue. Relancer le mode revue");
        griserChamps();
        $('#modifier').prop('value', 'Modifier');
        $('#modifier').prop('disabled', true);  
        $('#modifier').button('refresh');

        $('#nouveau').prop('value', 'Nouveau');
        $('#nouveau').prop('disabled', false);  
        $('#nouveau').button('refresh');

        $('#tableau').attr('class', 'ui-grid-solo');   
        
        ChangerMode();
    },
    onMessage: function(e){
        //lampadairesProches(); //$.parseJSON(event.data);  
            var obj = JSON.parse(e.data);
            tab = obj.enregistrement;
            genererTableau(tab);
    }
});
//var gpsSse = $.SSE("/cgi-bin/sse2.cgi",{
//
//    onOpen: function(){
//        console.log("Open"); 
//    },
//    onEnd: function(){
//        console.log("End"); 
//    },
//    onError: function(e){
//        console.log("Could not connect"); console.log(e);
//    },
//    onMessage: function(e){   
//            var obj = JSON.parse(e.data);
//            char =obj.LATITUDE;
//            char1 =obj.LONGITUDE;
//            char2 =obj.DATE;
//            char3  =obj.ALTITUDE;
//                    
//    }
//});

//Essais message d'attente
$("<div id=\"divLoading\" style=\"display:none; width: 130px; text-align: center; padding: 5px 0px 5px 0px;\">chargement...</div>").appendTo(document.body);






//var evtSource = new EventSource('/cgi-bin/sse.cgi');
//evtSource.onmessage = function(e) {
//    console.log("Message"); console.log(e);
//    $("#dLatitude").val(e.data);
//};
//evtSource.onopen = function () {
//    console.log("OpenConnection.");
//};
////evtSource.addEventListener('message', function(e) {
////    $("#dLongitude").val(e.data);
////    console.log("Message event"); console.log(e);
////
////}, false);
//    console.log("Error"); console.log(e);
//    console.log(e.data);
//};

function ChangerMode() {
        griserChamps();
        $('#modifier').prop('value', 'Modifier');
        $('#modifier').button('refresh');

        $('#modifier').prop('disabled', true);  
        $('#modifier').button('refresh');  

        $('#supprimer').prop('disabled', true);
        $('#supprimer').button('refresh');    

        if($('#modeRevue').val() == 'Revue'){       
            $('.ui-content').css("background-color", color);   
            $('#modeRevue').val('Création');
            $('#nouveau').prop('disabled', true);
            $('#nouveau').button('refresh');
            
            sse.start();            

        }else{
            $('#modeRevue').val('Revue');  
            $('.ui-content').css("background-color", color);
            $('#nouveau').prop('disabled', false);
            $('#nouveau').button('refresh');            
            sse.stop();
            displayList();

        }
        $('#modeRevue').button('refresh');
        return;    
};
function majbackground(){
    
}

function ClicTableau () {
	
    //if(!($("#tab2").hasClass("ui-disabled")))

    if(!($("#tableau").hasClass("ui-disabled")))
    {
    	$('#modifier').prop('disabled', false);  //Change l'état de disable
    	$('#modifier').button('refresh'); // Le bouton se met a jour 
    	$('#supprimer').prop('disabled', false);
    	$('#supprimer').button('refresh');

        var value = "";


         $('tr').css("background-color",colortab);
         $('tr').css("color", 'black');
         $(this).closest("tr").css("background-color", color);
         $(this).closest("tr").css("color",colortab);
         
         //var trId = document.getElementById("0");
	 trId = $(this).closest("tr").attr("id");

         $('#dLatitude').val(tab[trId].LATITUDE);
         $('#dLongitude').val(tab[trId].LONGITUDE);
         
//ajout des nouveaux champs
        $('#dAltitude').val(tab[trId].ALTITUDE);
        $('#dSatellites').val(tab[trId].SATELLITES);
        $('#dNbrMesures').val(tab[trId].NBRMESURES);
        $('#dfix').val(tab[trId].FIX);
        $('#dPrecision').val(tab[trId].PRECISION);
       
       $('#dheight').val(tab[trId].HEIGHT);
         $('#dPuissance').val(tab[trId].POWER);
         $('#dTown').val(tab[trId].TOWN);
         $('#dStreet').val(tab[trId].STREET);
         $('#dNotes').val(tab[trId].NOTES);      
         $('#dLum').val(tab[trId].FLUX);
         $('#dlampadaire').val(tab[trId].STREETLIGHT);
         $('#dlampadaire').selectmenu('refresh');
         $('#dAmpoule').val(tab[trId].LAMP);
         $('#dAmpoule').selectmenu('refresh');         
         $('#dAlbedo').val(tab[trId].ALBEDO);
         $('#dAlbedo').selectmenu('refresh');  
         $('#dULOR').val(tab[trId].ULOR+"%");
         $('#dULOR').selectmenu('refresh');
         dateEnregistrement=tab[trId].DATE;
         identifiant=tab[trId].ID;

    $('#modifier').prop('disabled', false);          //Change l'état de disable
    $('#supprimer').prop('disabled', false);                    // Le bouton se met a jour     
    }
};

function getIdentifiant() {
	$.ajax({
		method: 'POST',
		url: "/cgi-bin/identifiant.cgi",
		dataType: "json",

		success: function(data){
			if(data.SUCCESS == "OK")
				identifiant = data.IDENTIFIANT;				
		
		},
                error: function (reponse,status) {
                    alert("Attention! identifiant erroné. " + reponse );
                }


	});

}
function Nouveau() {
	//getIdentifiant();
	if ($('#nouveau').val() == 'Nouveau') //Si le bouton nouveau vaut "nouveau"
	{

    $('#save').prop('disabled', true);

    $('#save').button('refresh');   

    $('#chargement').show();

    $('#geoFix').show();

    $('#btnGps').hide(); 

    $('#btnRed').show();

    $('#geo').prop('disabled', true);

    $('#geo').button('refresh');

    sse.stop();

//  

//    gpsSse.start();   

//    

//    

//     if (obj.LATITUDE && obj.LONGITUDE && obj.DATE && obj.ALTITUDE)

//                {

//                    $("#dLatitude").val(obj.LATITUDE);

//                    $("#dLongitude").val(obj.LONGITUDE);

//                    $("#dAltitude").val(obj.ALTITUDE);

//                    $('#save').prop('disabled', false);

//                    $('#save').button('refresh');

//                    dateEnregistrement=obj.DATE;       

//                   gpsSse.stop();   

//                    $('#btnGps').show(); 

//                    $('#btnRed').hide();

//                    $('#chargement').hide();

//                }

//    

    $.ajax({

      

        type: 'POST',

        url: '../cgi-bin/gps.cgi',

        dataType: 'json',

          

            //data : 'geolocaliser', ne fonctionne pas sur Chrome

//        beforeSend: function () { $("#divLoading").show(); },  //------------------------------------------------------

//        complete: function () { $("#divLoading").fadeOut(); },  //------------------------------------------------------          

        success: function (reponse,status) {

                        //console.log((reponse));

                        

            if (reponse.ERREUR === '-2') 

            {

                alert("GPS non branché." );

                $("#dLatitude").val("XX.XXXXXX");

                $("#dLongitude").val("XX.XXXXXX");

                $("#dAltitude").val("XXX");                    

            }

            else if (reponse.ERREUR === '-1') 

            {

                alert("FIX non obtenu." );

                $("#dLatitude").val("XX.XXXXXX");

                $("#dLongitude").val("XX.XXXXXX");

                $("#dAltitude").val("XXX");                   

            }



            else if (reponse.LATITUDE && reponse.LONGITUDE && reponse.DATE && reponse.ALTITUDE)

            {

                $("#dLatitude").val(reponse.LATITUDE);

                $("#dLongitude").val(reponse.LONGITUDE);

                $("#dAltitude").val(reponse.ALTITUDE);

                $('#save').prop('disabled', false);

                $('#save').button('refresh');

                dateEnregistrement=reponse.DATE;       



            }

            else alert("reponse = " + reponse.LATITUDE + ", " + reponse.LONGITUDE+ ", " + reponse.ALTITUDE);

            $("#dSatellite").val(reponse.SATELLITES);

            $("#dFix").val(reponse.FIX);

            $("#dPrecision").val((reponse.HDOP));

            $("#dNbrMesures").val(reponse.ACQUISITIONS);                

            $('#btnGps').show(); 

            $('#btnRed').hide();

            $('#chargement').hide();

            if (($('#nouveau').val() === 'Annuler') || ($('#modifier').val() === 'Annuler'))

            {

                $('#geo').prop('disabled', false);  

                $('#geo').button('refresh');

            }

            if ($('#modeRevue').val() === 'Création')

            {

                sse.start();

            }

        },

        error: function (reponse,status, erreur) {

            alert("Problème éventuel de conflit. Recommencer.");

            $('#btnGps').show(); 

            $('#btnRed').hide();

            $('#chargement').hide();

            if (($('#nouveau').val() === 'Annuler') || ($('#modifier').val() === 'Annuler'))

            {            

                $('#geo').prop('disabled', false); 

                $('#geo').button('refresh');

            }

            if ($('#modeRevue').val() === 'Création')

            {

                griserChamps();

                $('#modifier').prop('value', 'Modifier');

                $('#modifier').prop('disabled', true);  

                $('#modifier').button('refresh');



                $('#nouveau').prop('value', 'Nouveau');

                $('#nouveau').prop('disabled', false);  

                $('#nouveau').button('refresh');



                $('#tableau').attr('class', 'ui-grid-solo');   



                ChangerMode();

            }            

        }



    });


            $('#nouveau').prop('value', 'Annuler'); //On change sa valeur en "annuler"
            $('#nouveau').button('refresh'); //On refresh le bouton     

            $('#modifier').prop('disabled', true); //griser le bouton modifier  
            $('#modifier').button('refresh');

            degriserChamps(); //On degrise les champs

            $('#tableau').attr('class', 'ui-disabled ui-grid-solo'); //On grise le tableau

	    $('#save').prop('disabled', true); //on grise le bouton enregistrer
	    $('#save').button('refresh');


	} else { //si le bouton nouveau est a l'état "annuler"

            $('#tableau').attr('class', 'ui-grid-solo'); //On degrise le tableau

            $('#nouveau').prop('value', 'Nouveau'); //On repasse sa valeur a "Nouveau"
            $('#nouveau').button('refresh');

            griserChamps(); //On grise les champs
	}
};

 function Modifier() {  
    if($('#modifier').val() === 'Modifier')
    {
        degriserChamps();
        $('#modifier').prop('value', 'Annuler');
        $('#modifier').button('refresh');

        $('#nouveau').prop('disabled', true);  
        $('#nouveau').button('refresh');
        //$('#tab2').attr('class', 'ui-disabled ui-listview');
        $('#tableau').attr('class', 'ui-disabled ui-grid-solo'); //On grise le tableau

        $('#save').prop('disabled', false);  
        $('#save').button('refresh');

        return; 
    } else {

        griserChamps();
        $('#modifier').prop('value', 'Modifier');
        $('#modifier').button('refresh');

        $('#modifier').prop('disabled', true);  
        $('#modifier').button('refresh');

        $('#nouveau').prop('disabled', false);  
        $('#nouveau').button('refresh');

        //$('#tab2').attr('class', 'ui-listview');
        $('#tableau').attr('class', 'ui-grid-solo'); //On degrise le tableau
        return;
    }
    
};

function Supprimer ()
{
    var demandeConfirm = confirm("Voulez-vous vraiment effacer cet enregistrement ?");
 
    if(demandeConfirm){ // bouton ok cliquer
//
//                        type: 'POST',
//                        url: '../cgi-bin/testsocket.cgi',
//                        dataType: "json",
//                        data : 'action=getLuminosite',
//                        success: function (data) {
//                            
//                        },
//                        error: function (data) {
//                                
//                        }
	formData = new FormData();
        formData.append('ID', identifiant);            
        var request = new XMLHttpRequest();
            request.onreadystatechange = function() {
                if ((this.readyState === 4)&&(this.status === 200)) {
                    //var indice = tab.findIndex(estLEnregistrement);
                    //tab.splice(indice,1);
                    tab.splice(trId,1);
                    genererTableau(tab);
                    $('#dLatitude').val('');
                    $('#dLongitude').val('');
                    $('#dAltitude').val('');
                }
            };           
        request.open("POST", "/cgi-bin/supprimer.cgi");
        request.send(formData);  
    }
}   


var stockage= new Array();
function lireListe() {   
    $.ajax({
        type: 'POST',
        url: '../cgi-bin/listes.cgi',
        dataType: 'json',
        //data : 'listeLampadaire',
        success: function (reponse,status) {
            stockage=reponse;
   	 console.log(reponse);
            $('#page1 .mesSelect').css('background-color',colortab);
           for(var i=0 ;i<stockage.LAMPADAIRE.length  ;i++)
           {
               $("#dlampadaire").append("<OPTION>"+ stockage.LAMPADAIRE[i] + "</OPTION>");
           }

           for(var i=0 ;i<stockage.AMPOULE.length ;i++)
           {
               $("#dAmpoule").append("<OPTION>"+ stockage.AMPOULE[i] + "</OPTION>");
           }

           for(var i=0 ;i<stockage.ULOR.length ;i++)
           {

               $("#dULOR").append("<OPTION>"+ stockage.ULOR[i] + "</OPTION>");
           }

           for(var i=0 ;i<stockage.ALBEDO.length ;i++)
           {

               $("#dAlbedo").append("<OPTION>"+ stockage.ALBEDO[i] + "</OPTION>");
           }

        },
        error: function (result, status, erreur) {
              alert( erreur);
        }
    }); 
};




function BoutonGeolocaliser() {   // NE Pas OULIER DE CHANGER LA PERMISSION
    $('#save').prop('disabled', true);
    $('#save').button('refresh');   
    $('#chargement').show();
    $('#geoFix').show();
    $('#btnGps').hide(); 
    $('#btnRed').show();
    $('#geo').prop('disabled', true);
    $('#geo').button('refresh');
    sse.stop();
//  
//    gpsSse.start();   
//    
//    
//     if (obj.LATITUDE && obj.LONGITUDE && obj.DATE && obj.ALTITUDE)
//                {
//                    $("#dLatitude").val(obj.LATITUDE);
//                    $("#dLongitude").val(obj.LONGITUDE);
//                    $("#dAltitude").val(obj.ALTITUDE);
//                    $('#save').prop('disabled', false);
//                    $('#save').button('refresh');
//                    dateEnregistrement=obj.DATE;       
//                   gpsSse.stop();   
//                    $('#btnGps').show(); 
//                    $('#btnRed').hide();
//                    $('#chargement').hide();
//                }
//    
    $.ajax({
      
        type: 'POST',
        url: '../cgi-bin/gps.cgi',
        dataType: 'json',
          
            //data : 'geolocaliser', ne fonctionne pas sur Chrome
//        beforeSend: function () { $("#divLoading").show(); },  //------------------------------------------------------
//        complete: function () { $("#divLoading").fadeOut(); },  //------------------------------------------------------          
        success: function (reponse,status) {
                        //console.log((reponse));
                        
            if (reponse.ERREUR === '-2') 
            {
                alert("GPS non branché." );
                $("#dLatitude").val("XX.XXXXXX");
                $("#dLongitude").val("XX.XXXXXX");
                $("#dAltitude").val("XXX");                    
            }
            else if (reponse.ERREUR === '-1') 
            {
                alert("FIX non obtenu." );
                $("#dLatitude").val("XX.XXXXXX");
                $("#dLongitude").val("XX.XXXXXX");
                $("#dAltitude").val("XXX");                   
            }

            else if (reponse.LATITUDE && reponse.LONGITUDE && reponse.DATE && reponse.ALTITUDE)
            {
                $("#dLatitude").val(reponse.LATITUDE);
                $("#dLongitude").val(reponse.LONGITUDE);
                $("#dAltitude").val(reponse.ALTITUDE);
                $('#save').prop('disabled', false);
                $('#save').button('refresh');
                dateEnregistrement=reponse.DATE;       

            }
            else alert("reponse = " + reponse.LATITUDE + ", " + reponse.LONGITUDE+ ", " + reponse.ALTITUDE);
            $("#dSatellite").val(reponse.SATELLITES);
            $("#dFix").val(reponse.FIX);
            $("#dPrecision").val((reponse.HDOP));
            $("#dNbrMesures").val(reponse.ACQUISITIONS);                
            $('#btnGps').show(); 
            $('#btnRed').hide();
            $('#chargement').hide();
            if (($('#nouveau').val() === 'Annuler') || ($('#modifier').val() === 'Annuler'))
            {
                $('#geo').prop('disabled', false);  
                $('#geo').button('refresh');
            }
            if ($('#modeRevue').val() === 'Création')
            {
                sse.start();
            }
        },
        error: function (reponse,status, erreur) {
            alert("Problème éventuel de conflit. Recommencer.");
            $('#btnGps').show(); 
            $('#btnRed').hide();
            $('#chargement').hide();
            if (($('#nouveau').val() === 'Annuler') || ($('#modifier').val() === 'Annuler'))
            {            
                $('#geo').prop('disabled', false); 
                $('#geo').button('refresh');
            }
            if ($('#modeRevue').val() === 'Création')
            {
                griserChamps();
                $('#modifier').prop('value', 'Modifier');
                $('#modifier').prop('disabled', true);  
                $('#modifier').button('refresh');

                $('#nouveau').prop('value', 'Nouveau');
                $('#nouveau').prop('disabled', false);  
                $('#nouveau').button('refresh');

                $('#tableau').attr('class', 'ui-grid-solo');   

                ChangerMode();
            }            
        }

    });

    
    
    
};

function mesureLux(){
        $.ajax({
                type: 'POST',
                url: '../cgi-bin/testsocket.cgi',
                dataType: "json",
                data : 'action=getLuminosite',
                success: function (data) {
                    if(data.success == "OK")
                    {
                        $('#bLux').prop('disabled', false);
                        $('#bLux').button('refresh');
                        $('#dLum').textinput('disable');
                        $("#dLum").val(data.luminosite);
                    }
                    else
                        alert(data.message);
                },
                error: function (data) 
                    {
                       $('#bLux').prop('disabled', true);
                       $('#bLux').button('refresh');
                       $('#dLum').textinput('enable');
                       alert("Capteur non prêt, veuillez rentrer les valeurs manuellements")
                }
        });
};




$( document ).on( "pageinit", function() {
    $( ".photopopup" ).on({
        popupbeforeposition: function() {
            var maxHeight = $( window ).height() - 60 + "px";
            $( ".photopopup img" ).css( "max-height", maxHeight );
        }
    });
});


//Ajouter des photos
$(function(){
if (window.File && window.FileReader && window.FormData) {
    $('#capture').on('change', function (e) {
        var file = e.target.files[0];
        if (file) {
            if (/^image\//i.test(file.type)) {
                readFile(file);
            }
        }
		$('#capture').val("");
    });
}
});

function readFile(file) {
	var reader = new FileReader();

	reader.onloadend = function () {
		$('#miniature').append("<div id='mini' style='position:relative'><img src='"+reader.result+"' height='10%'></div>");
		tabPhoto.push(reader.result);
	}

	reader.onerror = function () {
		alert('Erreur : Lecture!');
	}

	reader.readAsDataURL(file);
}


function envoi(identifiant) {


    var formData = new FormData();  //Cr�er un ensemble de paires cl�/valeur

    for(var nbPhoto = 0; nbPhoto < tabPhoto.length; nbPhoto++){
            formData.append('photo'+nbPhoto, tabPhoto[nbPhoto]); //Ajoute la valeur photo/image
    }
	
        formData.append('identifiant' ,identifiant);
	formData.append('nbPhoto', tabPhoto.length);
	$.ajax({
            type: 'POST',
            url: '../cgi-bin/upload.cgi', //Lien du script cgi
            data: formData,
            contentType: false, //Empêche jquery de mettre un contentType
            processData: false, //Empêche JQUERY de convertir les valeurs en string
            success: function (data) {
                if (data.success) {
                    alert('Succés: upload!');
                }

            },
            error: function (data) {
                 alert('Erreur lors de l\'upload!');
            }
        });
	
	tabPhoto.length = 0;
}

$(document).on('click', '#remove', function(){
	$(this).parent().remove();
});
$(document).on('click', '.remove', function(){
    $(this).parent().remove();
});


function stopSystem ()
{
     var demandeConfirm = confirm("Voulez-vous vraiment éteindre le système ?");
 
    if(demandeConfirm){ // bouton ok cliquer
    $.ajax({
        type: 'POST',
        url: '../cgi-bin/shutdown.sh',
        success: function (reponse,status) {
                        console.log("shutdown OK");

        }
    });
    }
}


function allDelete ()
{
     var demandeConfirm = confirm("Voulez-vous vraiment supprimer toutes les données ?");
 
    if(demandeConfirm){ // bouton ok cliquer
    $.ajax({
        type: 'POST',
        url: '../cgi-bin/viderTable.cgi',
        success: function (reponse,status) {
            displayList();

        },
        error: function (reponse,status) {
 	   alert("Echec delete " );
        }
    });
    }
}
function colordefault()
{
var colorjour= "#0000A9";
var colortabjour= "#FFFFFF";   
var colornuit= "#410202";
var colortabnuit= "#c19b9b";  


if($('#buttoncolor').val() === 'Jour'){
color=colorjour;
colortab=colortabjour;
$('#buttoncolor').val('Nuit');
}

else{
$('#buttoncolor').val('Jour');
color=colornuit;
colortab=colortabnuit;
}
$('#buttoncolor').button('refresh');

$('#page1 .ui-content').css("background-color", color); 
$('#page1 .ui-btn').css('background-color',colortab);
$('#page1 .mesSelect').css('background-color',colortab);
$('#page1 .ui-body-inherit').css('background-color',colortab);
$('#page1 .ui-responsive').css("background-color", colortab); 
$('#page1 tr').css("background-color",colortab);
$(this).closest("#page1 tr").css("color",colortab);
}
function majCouleur() 
		{ 
var majcouleur;
var majcouleurtab;

   majcouleur =$('#head').val()
   color=majcouleur;
    if($('#dColor').val()!=""){
    majcouleur =$('#dColor').val()
    color=majcouleur;
    }
    
    majcouleurtab =$('#head1').val()
   colortab=majcouleurtab;
    if($('#dColor1').val()!=""){
    majcouleurtab =$('#dColor1').val()
    colortab=majcouleurtab;
    }
    
    
   $('#page1 .ui-content').css("background-color", color); 
   $('#page1 .ui-btn').css('background-color',colortab);
   $('#page1 .ui-body-inherit').css('background-color',colortab);
   $('#page1 .ui-responsive').css("background-color", colortab); 
   $('#page1 tr').css("background-color",colortab);
   $(this).closest("#page1 tr").css("color",colortab);
   
}	
function envoimailbdd(){
    var demandeConfirm = confirm("Voulez-vous transmettre la base de données ?");
 
    if(demandeConfirm){ // bouton ok cliquer
	$.ajax({
            type: 'POST',
            url: '../cgi-bin/envoyerBDD.cgi', //Lien du script cgi
            dataType: 'json',

            success: function (reponse,status) {
                switch (reponse.ERREUR)
                {
                    case '1':
                        alert('Envoi terminé. Vérifier la réception avant suppression.');
                        break;
                    case '-1':
                        alert('Problème avec le serveur SMTP.');
                        break;   
                    case '-2':
                        alert('Envoi impossible. Internet non disponible.');
                        break;    
                    case '-3':
                        alert('Envoi impossible. Fichier de configuration non trouvé.');
                        break;  
                    case '-4':
                        alert('Envoi impossible. Problème de configuration du client messagerie.');
                        break;                    
                }

            },
            error: function (data) {
                 alert('Erreur lors de l\'envoi');
            }
        }); 
    }
 
}

