Η parser θα διαβάζει την είσοδο και θα τη φορτώνει στη μνήμη στην κατάλληλη μορφή (array από vectors για vector space, array από strings για hamming space και array από doubles/integers για metric space για το οποίο γνωρίζουμε μόνο τις αποστάσεις μεταξύ των αντικειμένων).
Στη συνέχεια θα περνάει τη μνήμη αυτή καθώς και μερικά ακόμα arguments στη συνάρτηση (αντίστοιχη της f ή g στις διαφάνειες) που κατασκευάζει το hashtable όταν το argument που αντιστοιχεί στο seed της είναι NULL (null είναι την πρώτη φορά που καλείτε, η ίδια παράγει μια τιμή η οποία επιστρέφεται δια μέσου του ίδου pointer και χρησιμοποιήται για τις επόμενες κλείσεις ώστε κάθε φορά να έχουμε την ίδια g), ενώ όταν δεν είναι και δεν είναι null ούτε το argument που αντιστοιχεί στο query, επιστρέφει το bucket του query. Έχουμε L διαφορετικές g σε κάθε εκτέλεση, διαφορετικές υπό την έννοια ότι καλείται η g L φορές ώστε να παραχθούν L διαφορετικά hashtables και τα αντίστοιχα seeds. Η parser(θέλει καλύτερο όνομα) στη συνέχεια θα αναζητά μέσα στο bucket τα κατάλληλα p σύμφωνα με το q και το r, αυτό για L hashtables.

# README #

This README would normally document whatever steps are necessary to get your application up and running.

### What is this repository for? ###

* Quick summary
* Version
* [Learn Markdown](https://bitbucket.org/tutorials/markdowndemo)

### How do I get set up? ###

* Summary of set up
* Configuration
* Dependencies
* Database configuration
* How to run tests
* Deployment instructions

### Contribution guidelines ###

* Writing tests
* Code review
* Other guidelines

### Who do I talk to? ###

* Repo owner or admin
* Other community or team contact