# Homework 7

Solve the murder mystery we started exploring in class.

I'd advise you to have pen and paper to note important info.

Be prepared to spend an hour or two on this.

Have a look at the schema image so you know what columns are in the table:
![schemaImage](schema.png)

Write each of your sqlite3 queries in files called queryNameXYZ.sql.
You'll probably need to write 10 or so queries. I don't see you needing more
than 20.

A sample query file would contain:

```
SELECT * FROM person LIMIT 1;
```

and you run it like:

```
user@machine$ sqlite3 sql-murder-mystery.db < sqlQuery1.sql
# output comes out here
``` 

## Submission:

* all of your query files
* screenshot of you running a query on your computer
* solution.txt telling me who the murderer is!

Due via pull request by 11:59 PM of Monday, March 16th. Please put your
submission in Homework/Week07/StudentSubmissions/YourName.