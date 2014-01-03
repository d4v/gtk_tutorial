#include <stdlib.h>
#include <gtk/gtk.h>
 
 
void cb_ok (GtkWidget * p_wid, gpointer p_data)
{
   GtkWidget   * p_dialog  = NULL;
   GtkEntryBuffer * p_buf = p_data;
   const char * p_text = gtk_entry_buffer_get_text(p_buf);
 
 
   if (p_text != NULL)
   {
      p_dialog = gtk_message_dialog_new (
         NULL,
         GTK_DIALOG_MODAL,
         GTK_MESSAGE_INFO,
         GTK_BUTTONS_OK,
         "%s",
         p_text
      );
 
 
      gtk_dialog_run (GTK_DIALOG (p_dialog));
      gtk_widget_destroy (p_dialog);
   }
}
 
void cb_quit (GtkWidget * p_wid, gpointer p_data)
{
   gtk_main_quit ();
}
 
 
int main (int argc, char ** argv)
{
   GtkBuilder  *  p_builder   = NULL;
   GError      *  p_err       = NULL;
 
 
   /* Initialisation de GTK+ */
   gtk_init (& argc, & argv);
 
 
   /* Creation d'un nouveau GtkBuilder */
   p_builder = gtk_builder_new ();
 
   if (p_builder != NULL)
   {
      /* Chargement du XML dans p_builder */
      gtk_builder_add_from_file (p_builder, "TutorielGladeGTK.glade", & p_err);
 
      if (p_err == NULL)
      {
         /* 1.- Recuparation d'un pointeur sur la fenetre. */
         GtkWidget * p_win = (GtkWidget *) gtk_builder_get_object (
            p_builder, "window1"
         );
 
         /* 2.- Connection des signaux par le builder */
         gtk_builder_connect_signals(p_builder,NULL);
 
         gtk_widget_show_all (p_win);
         gtk_main ();
      }
      else
      {
         /* Affichage du message d'erreur de GTK+ */
         g_error ("%s", p_err->message);
         g_error_free (p_err);
      }
   }
 
 
   return EXIT_SUCCESS;
}

