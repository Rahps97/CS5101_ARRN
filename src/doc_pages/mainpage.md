@mainpage CS5101 Mid Semester Assignment - Group 24
@tableofcontents

**Topic: Ecommerce Platform**<br/>
*Authored by members of Group 24*<br/>


Members:<br/>
    @ref contributorsniku - 16MS077<br/>
    @ref contributorsrahul - 16MS064<br/>
    @ref contributorsakash - 16MS147<br/>
    @ref contributorsrohit - 16MS176<br/>

The database of the application is seeded with some dummy data to test the application.<br/>
@subpage data

###Build Application###
The application uses Makefile to automate its build process. So building the application from source file will vary on different operating systems.<br/>
####Linux/MacOS###
Run following command from root directory of the project to build the application.<br/>
####Seed database with dummy data####
<div style='background-color: #d0d7ea; padding: 10px 15px'>**make seed**</div>
<div style='background-color: #d0d7ea; padding: 10px 15px'><b>./seed</b></div>
####Build the project####
<div style='background-color: #d0d7ea; padding: 10px 15px'>**make**</div>
####Launch Application####
<div style='background-color: #d0d7ea; padding: 10px 15px'><b>./main</b></div>
####Take backup of the database####
<div style='background-color: #d0d7ea; padding: 10px 15px'>**make backup_db**</div>
####Restore databse from previous backup####
<div style='background-color: #d0d7ea; padding: 10px 15px'>**make restore_db**</div>
####Remove all binaries of the application####
<div style='background-color: #d0d7ea; padding: 10px 15px'>**make clean**</div>
####Remove all binaries and also clean database####
<div style='background-color: #d0d7ea; padding: 10px 15px'>**make reset**</div>
####Windows###
To build project in Download GnuWin32 so that **make** command is available in command prompt. Rest all the intructions to build application is same as given above.
