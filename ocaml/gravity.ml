(* ocaml gravity.ml   *)
#load "graphics.cma";;

open Graphics;;
Random.self_init ();;
Graphics.open_graph " 1024x768";;
class planet =
    object (*   x e y nello spazio sono diverse da quelle nella finestra( anche la speed ...)*)
		val mutable x =  Random.float 359.
		val mutable y =  Random.float 239.
		val mutable mass =  300000
		val mutable speed =  0.
		val mutable direction =  0.
		
		val mutable color =  rgb (Random.int 256)(Random.int 256)(Random.int 256)
		method get_x = x
		method get_y = y 
		method set_x newx= x<-newx
		method set_y newy  = y <-newy
		method set_color c = color <- c
		method get_color   = color  
		method set_mass m = mass <- m
		method get_mass   = mass  
		method set_speed s = speed <- s  
		method get_speed  = speed  
		method set_direction d = direction <- d
		method get_direction   = direction  
		method stampa = Printf.printf "x%.8f y%.8f mass%.8f speed%.8f direction%.8f\n"  x y mass speed direction
		method disegna = set_color(color);     Graphics.plot  x y 
end;;

let   distanza p1 p2  =(sqrt((float((p1#get_x -p2#get_x))**2.) +.(float((p1#get_y -p2#get_y))**2.)));;
let   stampa_distanza p1 p2  =
	Printf.printf   "dist %.8f   \n"  (distanza p1 p2 );;

let  rec distanza_minima p  lista dist=
	match lista  with
		| []-> p#disegna
		|p1::coda -> let newdist=distanza p p1 in
							if  newdist < dist then 
														begin 	p#set_color p1#get_color;
																distanza_minima p  coda  newdist 
														end
							else  distanza_minima p  coda  dist;
;;

let rec make_list  length =
	match length with
		|0->[]
		|_ -> let p=new planet in p::(make_list  (length-1))
;;

let rec print_list  lista =
	match lista  with
		| []->Printf.printf "fine\n"
		|p::coda -> p#stampa;  print_list coda
;;
let rec print_disegna  lista =
	match lista  with
		| []->Printf.printf "fine\n"
		|p::coda -> p#disegna;  print_disegna coda
;;
let rec print_dist  lista punto=
	match lista  with
		| []->Printf.printf "fine\n"
		|p::coda -> distanza p punto  ;print_dist coda punto
;;
let   asd=make_list 100 in (*print_list asd;print_dist asd (new point);print_disegna asd;*)
	for i = 0 to 359 do 
		for k = 0 to 239 do 
			let punto=new point in 
					punto#set_x i ;
					punto#set_y k ; (*punto#stampa; *)
					distanza_minima  punto asd 10000. 
		done
	done;;
read_line ();;
 






