 function degriserChamps () 
{  
    $('#supprimer').prop('disabled', true);  
    $('#supprimer').button('refresh');
    $('#dlampadaire').selectmenu('enable');
    $('#dULOR').selectmenu('enable');
    $('#dAmpoule').selectmenu('enable');
    $('#dheight').textinput('enable');
    $('#dPuissance').textinput('enable');   
    $('#dAlbedo').selectmenu('enable');
    $('#dTown').textinput('enable');
    $('#dStreet').textinput('enable');
    $('#dNotes').textinput('enable');
    $('#bLux').prop('disabled', false);  
    $('#bLux').button('refresh');
    $('#dLum').textinput('disable');
    $('#geo').prop('disabled',false);
    $('#geo').button('refresh');

    $('#pic').attr('class', 'ui-btn ui-corner-all ui-btn-inline');
};

function griserChamps () 
{
    $('#supprimer').prop('disabled', true);  
    $('#supprimer').button('refresh');
  
    $('#dlampadaire').selectmenu('disable');   
    $('#dULOR').selectmenu('disable');  
    $('#dAmpoule').selectmenu('disable');  
    $('#dheight').textinput('disable');  
    $('#dPuissance').textinput('disable');  
    $('#dAlbedo').selectmenu('disable');  
    $('#dTown').textinput('disable');  
    $('#dStreet').textinput('disable');  
    $('#dNotes').textinput('disable');  

    $('#bLux').prop('disabled', true);  
    $('#bLux').button('refresh');  
    $('#dLum').textinput('disable');
    
    $('#geo').prop('disabled', true); 
    $('#geo').button('refresh'); 

     $('#pic').attr('class', 'ui-btn ui-corner-all ui-btn-inline ui-disabled');
    
    $('#save').prop('disabled', true);
    $('#save').button('refresh');
};

function modifierBtnNouveau()
{
    if ($('#nouveau').val() == 'Nouveau')
    {
        //Degrise tout quand clic sur nouveau   
        $('#nouveau').prop('value', 'Annuler');
        $('#nouveau').button('refresh');
        return;
    }
    else 
    {
        $('#nouveau').prop('value', 'Nouveau');
        $('#nouveau').button('refresh');
        return;
    }
};

function modifierBtnModifier()
{
    if ($('#modifier').val() == 'Modifier')
    {
        //Degrise tout quand clic sur nouveau   
        $('#modifier').prop('value', 'Annuler');
        $('#modifier').button('refresh');
        return;
    }
    else 
    {
        $('#modifier').prop('value', 'Modifier');
        $('#modifier').button('refresh');
        return;
    }
};

function degriserTableau()
{
    //$('#tab2').attr('class', ' ui-listview');
    $('#tableau').attr('class', 'ui-grid-solo'); //On degrise le tableau
};

function griserTableau()
{
    //$('#tab2').attr('class', 'ui-disabled ui-listview');
    $('#tableau').attr('class', 'ui-disabled ui-grid-solo'); //On grise le tableau
};

function degriserBtnSuppModif()
{
    $('#supprimer').prop('disabled', false);  
    $('#supprimer').button('refresh');
    $('#modifier').prop('disabled', false);  
    $('#modifier').button('refresh');
};

function griserBtnSuppModif()
{
    $('#supprimer').prop('disabled', true);  
    $('#supprimer').button('refresh');
    $('#modifier').prop('disabled', true);  
    $('#modifier').button('refresh');
};

function griserBtnSuppSave()
{
    $('#supprimer').prop('disabled', true);  
    $('#supprimer').button('refresh');
    $('#nouveau').prop('disabled', true);  
    $('#nouveau').button('refresh');
};

function griserBtnSuppSave()
{
    $('#supprimer').prop('disabled', true);  
    $('#supprimer').button('refresh');
    $('#nouveau').prop('disabled', true);  
    $('#nouveau').button('refresh');
};

//function remplirChamps()
//{
//    var value = "";
//    $(this).find('td').each(function(i)
//        {
//         $('#donne'+i).val($(this).html());      
//        });
//    
//    $('#input1').val(value);
//};

function modeRevue()
{
    $('.ui-content').css("background-color", "blue");    
    $('#ChangMod').val('Création');
};

function modeEnregistrement()
{
    $('#ChangMod').val('Mode Revue');
    $('.ui-content').css("background-color", "#FCE2E2"); 
};