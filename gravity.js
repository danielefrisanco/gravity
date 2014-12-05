function forza( m1,m2,r){

var g=6.674*Math.pow(10,-11); //m^3 x kg^-1 x s^-2
return g*m1*m2 /Math.pow(r,2);
}


function acceleration_gravity_terra( ){
//9,80665 m/s²
/*
gloc = [1 - (2,637·10-3cos(2f) + 33,15·10-7h + 5·10-5)]gst [1]
gloc = 9.7803184[1 + 0.0053024sin2(f) - 5.9·10-6sin2(2f)] - 3.086·10-6h [2]

in cui h (in metri) è l'altezza sul livello del mare e f è la latitudine del luogo (Venezia = 45.433º). 


*/

var lat=45.433;//latitudine
var h=200;//altitudine
var gloc = (1 - (2.637*Math.pow(10,-3)*Math.cos(2*lat) + 33.15*Math.pow(10,-7)*h + 5*Math.pow(10,-5)))*9.80665;
var g=9.81;
return g;



}

function Pianeta(x,y,m,r){
	var x=x;
	var y=y;
	var mass=m;
	var distance=r; 
	var speed=0;
	 var direction=0

}