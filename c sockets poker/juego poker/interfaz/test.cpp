 /*

      Interfaz hueca

 */

 #include <iostream>
 #include "allegro5/allegro.h"
 #include "allegro5/allegro_font.h"
 #include "allegro5/allegro_ttf.h"
 #include "allegro5/allegro_image.h"
 #include "allegro5/allegro_primitives.h"

int main()
{
    ALLEGRO_BITMAP  *misimagenes[2] = {NULL};
    ALLEGRO_BITMAP  *mesaimagenes[5] = { NULL };
    ALLEGRO_BITMAP  *jugadores =  NULL ;
	  al_init();

	al_init_font_addon();
	al_init_image_addon();
	jugadores=al_load_bitmap("images.png");
	for(int i = 0; i < 5 ; i++){
       mesaimagenes[i]= al_load_bitmap("images.png");
       if(i<2)
           misimagenes[i] = al_load_bitmap("images.png");
       }

	ALLEGRO_DISPLAY* display = al_create_display(1200, 800);
	ALLEGRO_FONT* font = al_create_builtin_font();
	al_clear_to_color(al_map_rgb(0, 255, 0));
	al_draw_text(font, al_map_rgb(255, 255, 255), 400, 50, ALLEGRO_ALIGN_CENTER, "Juego Poker");
	al_draw_bitmap_region(misimagenes[0], 0, 0, 92, 143, 500, 600, 0);
	al_draw_bitmap_region(misimagenes[1], 92, 0, 92, 143, 600, 600, 0);
	for(int i = 0; i<5 ; i++)
       al_draw_bitmap_region(mesaimagenes[i], 92*i, 143, 92, 143, ((i*100)+ 350), 350, 0);

	//al_draw_bitmap(images,200,200,0);
	al_draw_bitmap_region(jugadores, 93*2, 143*4, 92, 143, 100, 250, 0);
	al_draw_bitmap_region(jugadores, 93*2, 143*4, 92, 143, 200, 250, 0);
   al_draw_bitmap_region(jugadores, 93*2, 143*4, 92, 143, 900, 250, 0);
	al_draw_bitmap_region(jugadores, 93*2, 143*4, 92, 143, 1000, 250, 0);
	al_draw_bitmap_region(jugadores, 93*2, 143*4, 92, 143, 350, 100, 0);
	al_draw_bitmap_region(jugadores, 93*2, 143*4, 92, 143, 450, 100, 0);
   al_draw_bitmap_region(jugadores, 93*2, 143*4, 92, 143, 750, 100, 0);
	al_draw_bitmap_region(jugadores, 93*2, 143*4, 92, 143, 850, 100, 0);


	al_flip_display();
	al_rest(5.0);
	al_ustr_free(input);

    al_destroy_display(display);

   for(int i = 0; i<5 ; i++)
   al_destroy_bitmap(mesaimagenes[i]);
   for(int i = 0; i<2 ; i++)
   al_destroy_bitmap(misimagenes[i]);
	return 0;
}
