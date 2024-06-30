  This program was created because a grocery store wanted to better understand the frequency of items being bought throughout the day, this way they can organize the layout of
their produce section most effectively. The program functions by receiving input via a text file which fills up throughout the day and scanning through that file while counting
how many times each individual item appears, which is then uploaded into a separate file before allowing a user to view the data with menu commands. I believe what I did best
in this program was fulfilling multiple processes in a more compact fashion, particularly my loop(lines 50-68) which both creates the backup file and produces my noDupesList vector, 
used later to display each item from the original text file once with its count. This was of course a change I made after I made two loops, one for the backup file, and one for the
noDupesList. As for improvements that could be made, perhaps I could have put my ProduceItem class into its own separate ".h" file and then included it in the main file to save
10 lines of code. I also may have been able to clean up the whitespace in output where I resorted to using numerous "cout << endl;" lines because I wanted the output to sort of
stay in place each time a menu command was given.

  By far the most challenging part of the code to figure out was how to list each item once while also showing its count after. At first I had planned to use two vectors, one to
store ints for the count, and one to store strings for the item name, both of which would have filled at the same time so an item's name and count would have the same index.
In my search for how to accomplish this, I did see **many** people suggest using maps, but I'm not comfortable with those and was sure I could find another way. Ultimately, I
ended up using my one noDupesList to skip duplicates while iterating over the text file and creating class items that stored an item's name and count. I believe the most
transferable skills I acquired from this project are the abilities to manipulate files and also to lookout for opportunities where multiple processes can be combined to
reduce redundant code. In fact, I ended up using that same combined processes skill in the lab for that module where I produced necessary output while also building my linked
list. This program should be easier to maintain, read, and adapt thanks to my numerous comments describing what each loop and if-else branch does, along with simple and
understandable variable names which help a reader to see which variables go where. It will also be trivial to add more menu options in the future, should the grocery store
desire to have more functionality from this program.
