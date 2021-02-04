#include "all.h"

#define tabPkg w->pkgData[w->currentPkg - 1]

/*
Function : hello
--------------------------------------------------------------------------------
Printf hello

--------------------------------------------------------------------------------
GtkWidget *widget : widget
gpointer data : pointer to data of type (void *)
--------------------------------------------------------------------------------

*/
void hello (GtkWidget *widget, void *ptr) {
    printf("Hello %p\n", ptr) ;
}

/*
Function : printMessage
--------------------------------------------------------------------------------
Prints a message in a new window

--------------------------------------------------------------------------------
GtkWidget *widget : widget
char *message : message to be eventually printed
--------------------------------------------------------------------------------

*/
void printMessage (GtkWidget *widget, char *message) {
    GtkWidget *window ;
    GtkWidget *grid ;

    window = createWindow("Message", 200, 100) ;
    grid = createGrid(window) ;
    addLabel(grid, 0, 0, message) ;

    gtk_widget_show_all(window);
}

/*
Function : createWindow
--------------------------------------------------------------------------------
Creates a gtk window

--------------------------------------------------------------------------------
char *windowTitle : title given to the window
uint16_t width : width of the window
uint16_t height : height of the window
--------------------------------------------------------------------------------
Return values
    The GtkWidget * pointing on the window
*/
GtkWidget * createWindow (char *windowTitle, uint16_t width, uint16_t height) {
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), (const gchar *)windowTitle) ;
    gtk_window_set_default_size(GTK_WINDOW (window), width, height);
    backgroundColor(window, "#999999" );
    return window ;
}

/*
Function : createGrid
--------------------------------------------------------------------------------
Creates a gtk grid attached a the window

--------------------------------------------------------------------------------
GtkWidget *window : window
--------------------------------------------------------------------------------
Return values
    The GtkWidget * pointing on the grid
*/
GtkWidget * createGrid (GtkWidget *window) {
    GtkWidget *grid = gtk_grid_new() ;
    gtk_container_add(GTK_CONTAINER(window), grid) ;
    g_object_set(grid, "margin", 12, NULL);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10) ;
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10) ;
    return grid ;
}

/*
Function : createInput
--------------------------------------------------------------------------------
Creates a gtk input

--------------------------------------------------------------------------------
char *placeholder : the value of the input's placeholder
--------------------------------------------------------------------------------
Return values
    The GtkWidget * pointing on the input
*/
GtkWidget * createInput (char *placeholder, GtkWidget *grid, uint8_t lin, uint8_t col) {
    GtkWidget *input = gtk_entry_new() ;
    gtk_entry_set_placeholder_text(GTK_ENTRY(input), placeholder) ;
    gtk_grid_attach(GTK_GRID(grid), input, lin, col, 1, 1) ;
    return input ;
}

/*
Function : addLabel
--------------------------------------------------------------------------------
Adds a label to the grid at position (lin, col)

--------------------------------------------------------------------------------
GtkWidget *grid : the grid pointer
uint8_t lin : lin position of the label
uint8_t col : col position of the label
char *str : label content
--------------------------------------------------------------------------------

*/
void addLabel (GtkWidget *grid, uint8_t lin, uint8_t col, char *str) {
    GtkWidget *label ;
    label = gtk_label_new((const gchar *)str) ;
    gtk_grid_attach(GTK_GRID(grid), label, col, lin, 1, 1) ;
}

/*
Function : backgroundColor
--------------------------------------------------------------------------------
Sets the background of a window

--------------------------------------------------------------------------------
GtkWidget *widget : widget
char *color : the color that you want in background
--------------------------------------------------------------------------------

*/
void backgroundColor (GtkWidget *widget, char *color) {
  GtkCssProvider * cssProvider = gtk_css_provider_new();

  char css[64] = "* { background-image :none; background-color :";
  strcat(strcat(css, color), ";}");

  gtk_css_provider_load_from_data(cssProvider, css,-1,NULL);
  GtkStyleContext * context = gtk_widget_get_style_context(widget);
  gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(cssProvider),GTK_STYLE_PROVIDER_PRIORITY_USER);
}



/*
Function : destroy
--------------------------------------------------------------------------------
Quits the program

--------------------------------------------------------------------------------
GtkWidget *widget : widget
gpointer data : void pointer
--------------------------------------------------------------------------------

*/
void destroy (GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

/*
Function : closeWindow
--------------------------------------------------------------------------------
Closes a window

--------------------------------------------------------------------------------
GtkWidget *widget : widget sent by callback functions
GtkWidget *window : window to be destroyed
--------------------------------------------------------------------------------

*/
void closeWindow (GtkWidget *widget, GtkWidget *window) {
    gtk_window_close(GTK_WINDOW(window)) ;
}


/*
Function : retrieveData
--------------------------------------------------------------------------------
Retrieves the content of a GtkEntry and sets it in *str

--------------------------------------------------------------------------------
GtkWidget *widget : widget
GtkWidget *input : the GtkWidget from which the value is retrieved
char **str : string in which is stored the retrieved value
--------------------------------------------------------------------------------

*/
void retrieveData(GtkWidget *widget, GtkWidget *input, char **str) {
    if (input == NULL)
        return ;
    if (gtk_entry_get_text (GTK_ENTRY (input)) != NULL){
       *str = (char *)gtk_entry_get_text (GTK_ENTRY (input));
   }
    else
        strcpy(*str, "") ;
}

/*
Function : retrieveComboBoxContent
--------------------------------------------------------------------------------
Retrieves the current value of a Gtk ComboBoxText

--------------------------------------------------------------------------------
GtkWidget *widget : widget
GtkWidget *box : the GtkWidget from which the value is retrieved
char **str : string in which is stored the retrieved value
--------------------------------------------------------------------------------

*/
void retrieveComboBoxContent (GtkWidget *widget, GtkWidget *box, char **str) {
    if (box == NULL)
        return ;
    if (gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(box)) != NULL)
        *str = (char *)gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(box)) ;
    else
        *str = NULL ;
}

/*
Function : retrieveInteger
--------------------------------------------------------------------------------
Retrieves an integer from a GtkEntry
Calls gtk.c/(retrieveData) to retrieve the entry as a string before converting it

--------------------------------------------------------------------------------
GtkWidget *widget : widget sent by callback function
GtkWidget *input : pointer to the Gtk input
int16_t *integer : integer to store the result
--------------------------------------------------------------------------------
Return values
    0 if all good
    ERR_ENTRY if the value is wrong
*/
uint8_t retrieveInteger (GtkWidget *widget, GtkWidget *input, int16_t *integer) {
    char *tmp = "" ;
    retrieveData(widget, input, &tmp) ;

    if (strlen(tmp) == 0) {
        *integer = 0 ;
        return 0 ;
    }
    //trimWhiteSpace(tmp) ;

    *integer = atoi(tmp) ;
    if (*integer <= 0) {
        return 1 ;
    }

    return 0 ;
}

/*
Function : retrieveDouble
--------------------------------------------------------------------------------
Retrieves a double from a GtkEntry
Calls gtk.c/(retrieveData) to retrieve the entry as a string before converting it

--------------------------------------------------------------------------------
GtkWidget *widget : widget sent by callback function
GtkWidget *input : pointer to the Gtk input
double *nb : double to store the result
--------------------------------------------------------------------------------
Return values
    0 if all good
    ERR_ENTRY if the value is wrong
*/
uint8_t retrieveDouble (GtkWidget *widget, GtkWidget *input, double *nb) {
    char *tmp = "" ;
    retrieveData(widget, input, &tmp) ;

    if (strlen(tmp) == 0) {
        *nb = 0 ;
        return 0 ;
    }
    //trimWhiteSpace(tmp) ;

    *nb = atof(tmp) ;
    printf("%lf\n", *nb) ;

    return 0 ;
}


void initProg (int argc, char **argv) {
    gtk_init(&argc, &argv);
    //askCredentials() ;
    askNumberPkg() ;
    gtk_main() ;
}


/*
Function : askNumberPkg
--------------------------------------------------------------------------------
Open a window that asks how many packages will be sent
Calls gtk.c/(getNumberPkg) when the button is clicked
*/
void askNumberPkg (void) {
    Window *w = malloc(sizeof(Window)) ;
    GtkWidget *button;
    GtkWidget *input ;

    if (w == NULL)
        return ;

    strcpy(w->winName, "Number of packages");
    w->window = createWindow(w->winName, 640, 360) ;
    w->grid = createGrid(w->window) ;

    addLabel(w->grid, 0, 0, "Enter the number of packages");
    input = createInput("Number of packages", w->grid, 0, 1);
    w->data = input;

    button = gtk_button_new_with_label("OK !!!");
    gtk_grid_attach(GTK_GRID(w->grid), button, 1,1,1,1);
    g_signal_connect(GTK_WIDGET(button), "clicked", G_CALLBACK(getNumberPkg), w);

    g_signal_connect(GTK_WIDGET(w->window), "destroy", G_CALLBACK(destroy), w);

    gtk_widget_show_all(w->window) ;
}


/*
Function : getNumberPkg
--------------------------------------------------------------------------------
Retrieves the number of packages that will be delivered
Calls gtk.c/(retrieveInteger) to retrieve the entry as an integer

--------------------------------------------------------------------------------
GtkWidget *widget : widget sent by callback function
Window *w : the window structure

*/
void getNumberPkg(GtkWidget *widget, Window *w) {
    int16_t nb = 0;
    retrieveInteger(widget, w->data, &nb) ;
    if (nb <= 0) {
        return ;
    }
    w->totalPkg = (uint8_t)nb ;
    w->currentPkg = 0 ;
    w->pkgData = malloc(nb * sizeof(PkgData)) ;
    if (w->pkgData == NULL)
        return ;
    setPkgInputs(widget, w);
}

void setPkgInputs (GtkWidget *widget, Window *w) {
    GtkWidget *button ;
    char title[15] = "" ;
    w->currentPkg++ ;

    if (w->currentPkg <= w->totalPkg) {
        sprintf(title, "Package %d/%d", w->currentPkg, w->totalPkg);
        gtk_window_set_title(GTK_WINDOW(w->window), (const gchar *)title) ;

        gtk_widget_destroy(w->grid) ;
        w->grid = createGrid(w->window);

        addLabel(w->grid, 0, 0, "Enter float as 0.3") ;

        w->data = createPkgInputs(w->grid);
        button = gtk_button_new_with_label("Send");
        gtk_grid_attach(GTK_GRID(w->grid), button, 0,3,1,1);
        g_signal_connect(GTK_WIDGET(button), "clicked", G_CALLBACK(getDataPkg), w);

        gtk_widget_show_all(w->window) ;
    } else {
        strcpy(title, "Packages check") ;
        gtk_window_set_title(GTK_WINDOW(w->window), (const gchar *)title) ;

        gtk_widget_destroy(w->grid) ;
        writeXLSX(w->pkgData, w->totalPkg) ;
    }
}

/*
Function : createPkgInputs
--------------------------------------------------------------------------------
Creates the inputs for the package data

--------------------------------------------------------------------------------
GtkWidget *grid: grid to which are attached the inputs ;
--------------------------------------------------------------------------------
Return values
    the pointer to an array of inputs
*/
PkgInputs * createPkgInputs (GtkWidget *grid) {
    PkgInputs *inputs = malloc(sizeof(PkgInputs)) ;

    if (inputs == NULL)
        return NULL ;

    inputs->weight = createInput("Weight", grid, 0, 1) ;
    inputs->length = createInput("Length", grid, 1, 1) ;
    inputs->height = createInput("Height", grid, 2, 1) ;
    inputs->width = createInput("Width", grid, 3, 1) ;
    inputs->emailRecipient = createInput("Recipient's email", grid, 0, 2) ;
    inputs->addressRecipient = createInput("Recipient address", grid, 1, 2) ;

    inputs->delay = gtk_combo_box_text_new() ;
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(inputs->delay), "2d", "2 days") ;
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(inputs->delay), "5d", "5 days") ;
    gtk_grid_attach(GTK_GRID(grid), inputs->delay, 2, 2, 1, 1) ;

    return inputs ;
}

void getDataPkg (GtkWidget *widget, Window *w) {
    char *str ;
    PkgInputs *inputs = w->data ;

    getDataPkgDoubles(widget, inputs, &tabPkg) ;

    retrieveData(widget, inputs->emailRecipient, &str);
    if (checkEmail(str) != 0) {
        printMessage(widget, "Invalid email") ;
        return ;
    }
    strcpy(tabPkg.emailRecipient, str);

    retrieveData(widget, inputs->addressRecipient, &str);
    if (strlen(str) == 0) {
        printMessage(widget, "Empty adress") ;
        return ;
    }
    strcpy(tabPkg.addressRecipient, str);

    retrieveComboBoxContent(widget, inputs->delay, &str) ;
    if (str == NULL) {
        printMessage(widget, "Empty deadline") ;
        return ;
    }

    str[1] = '\0' ;
    tabPkg.delay = atoi(str) ;
    free(w->data) ;
    setPkgInputs(widget, w) ;
}

void getDataPkgDoubles (GtkWidget *widget, PkgInputs *pkg, PkgData *pkgData) {
    double tmp ;

    retrieveDouble(widget, pkg->weight, &tmp);
    if (checkDouble(tmp) != 0) {
        printMessage(widget, "Invalid weight value") ;
        return ;
    }
    pkgData->weight = tmp ;

    retrieveDouble(widget, pkg->length, &tmp);
    if (checkDouble(tmp) != 0) {
        printMessage(widget, "Invalid length value") ;
        return ;
    }
    pkgData->length = tmp ;

    retrieveDouble(widget, pkg->height, &tmp);
    if (checkDouble(tmp) != 0) {
        printMessage(widget, "Invalid height value") ;
        return ;
    }
    pkgData->height = tmp ;

    retrieveDouble(widget, pkg->width, &tmp);
    if (checkDouble(tmp) != 0) {
        printMessage(widget, "Invalid width value") ;
        return ;
    }
    pkgData->width = tmp ;
}

uint8_t checkEmail (char *email) {
    char *at ;
    char *point ;

    at = strchr(email, '@') ;
    if (at == NULL || email == at)
        return 1 ;
    at++;
    point = at ;

    at = strchr(at, '@') ;
    if (at != NULL)
        return 1 ;

    at = strchr(email, '@') ;
    point = strchr(point, '.') ;
    if (point == NULL || email + strlen(email) - 1 == point || at + 1 == point)
        return 1 ;

    return 0 ;
}

uint8_t checkDouble (double d) {
    return d > 0 ? 0 : 1 ;
}
