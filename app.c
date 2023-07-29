#include <stdio.h>
#include <stdbool.h>
#include <gtk/gtk.h>

//Global variable
int digit1 = 0, digit2 = 0, num_digits = 0, sum_of_double_odds = 0, sum_of_evens = 0;
bool is_valid;
// Function to validate the credit card number
bool validateCreditCard(const char *cardNumber) {
    char *endptr;
    long long cc_number = strtoll(cardNumber, &endptr, 10);
    printf("%s\n%lld\n", cardNumber, cc_number);
    while (cc_number > 0)
    {
        digit2 = digit1;
        digit1 = cc_number % 10;

        // get even digits
        if (num_digits % 2 == 0)
        {
            sum_of_evens += digit1;
        }
        else
        {
            // odd digits
            int multiple = 2 * digit1;
            // split the digits and summations
            sum_of_double_odds += (multiple / 10) + (multiple % 10);
        }
        cc_number /= 10;
        num_digits++;
    }

    is_valid = (sum_of_evens + sum_of_double_odds) % 10 == 0;
    printf("%d", is_valid);
    return is_valid;
}

// Function to detect credit card manufacturer
const char* detectManufacturer() {
    int first_two_digits = (digit1 * 10) + digit2;
    printf("%d", first_two_digits);

    if (digit1 == 4 && num_digits >= 13 && num_digits <= 16 && is_valid)
    {
        return "VISA";
    }
    else if (first_two_digits >= 51 && first_two_digits <= 55 && num_digits == 16 && is_valid)
    {
        return "MASTERCARD";
    }
    else if ((first_two_digits == 34 || first_two_digits == 37) && num_digits == 15 && is_valid)
    {
        return "AMEX";
    }
    else
    {
        return "INVALID";
    }
}

// Callback function for the "Check" button
void on_check_button_clicked(GtkWidget *widget, gpointer data) {
    const char *cardNumber = gtk_entry_get_text(GTK_ENTRY(data));
    GtkWidget *resultLabel = GTK_WIDGET(g_object_get_data(G_OBJECT(widget), "result_label"));

    if (validateCreditCard(cardNumber)) {
        gtk_label_set_text(GTK_LABEL(resultLabel), "Valid Credit Card!");
    } else {
        gtk_label_set_text(GTK_LABEL(resultLabel), "Invalid Credit Card!");
    }

    GtkWidget *manufacturerLabel = GTK_WIDGET(g_object_get_data(G_OBJECT(widget), "manufacturer_label"));
    const char *manufacturer = detectManufacturer();
    gtk_label_set_text(GTK_LABEL(manufacturerLabel), manufacturer);
}

// Callback function for the exit button
void on_exit_button_clicked(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Create the main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Credit Card Validator & Manufacturer Detector");
    gtk_widget_set_size_request(window, 400, 400);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a grid container to center the components
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_container_add(GTK_CONTAINER(window), grid);

    GtkWidget *titleLabel = gtk_label_new("Card Validator");
    gtk_grid_attach(GTK_GRID(grid), titleLabel, 0, 0, 1, 1);
    gtk_widget_set_halign(titleLabel, GTK_ALIGN_CENTER);

    // Create an entry to input the credit card number
    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Enter Credit Card Number");
    gtk_grid_attach(GTK_GRID(grid), entry, 0, 1, 1, 1);

    // Create a label to display the validation result
    GtkWidget *resultLabel = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), resultLabel, 0, 2, 1, 1);

    GtkWidget *manufacturerLabel = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), manufacturerLabel, 0, 3, 1, 1);

    GtkWidget *checkButton = gtk_button_new_with_label("Check");
    g_signal_connect(checkButton, "clicked", G_CALLBACK(on_check_button_clicked), entry);
    g_object_set_data(G_OBJECT(checkButton), "result_label", resultLabel);
    g_object_set_data(G_OBJECT(checkButton), "manufacturer_label", manufacturerLabel);
    gtk_grid_attach(GTK_GRID(grid), checkButton, 0, 4, 1, 1);

    GtkWidget *exitButton = gtk_button_new_with_label("Exit");
    g_signal_connect(exitButton, "clicked", G_CALLBACK(on_exit_button_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), exitButton, 0, 5, 1, 1);

    gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(grid, GTK_ALIGN_CENTER);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
