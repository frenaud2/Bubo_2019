  
$(function() {
    $("#save").on('click', saveSelectedValeur);
    
});




function saveSelectedValeur()
{
	formData = new FormData();
        //formData.append('identifiant', identifiant);
	formData.append('theCar', $('#cars').val()); 
    
            var request = new XMLHttpRequest();
            request.onreadystatechange = function() {
                if (this.readyState === 4 && this.status === 200) {
                    console.log("It's OK");
                }
            };
            
            request.open("POST", "/cgi-bin/test.cgi");
            request.send(formData);

}













