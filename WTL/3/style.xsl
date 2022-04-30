<?xml version="1.0" encoding="UTF-8"?>
<!-- w3 standards -->
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
    <body>
        <h1>Employee database</h1>
        <table border="2">
           <tr>
               <th>Name</th>
               <th>Age</th>
               <th>JD</th>
           </tr> 
           <!-- to extract the xml elements and add it to the output string of xsl transformation -->
           <xsl:for-each select="employee/personaldetails">
           <tr>            <!-- row -->
                <td><xsl:value-of select="name" /></td> <!-- cell value -->
                <td><xsl:value-of select="age" /></td>
                <td><xsl:value-of select="jd" /></td> 
            </tr>
            </xsl:for-each>
        </table>
    </body>
</html>
</xsl:template>
</xsl:stylesheet>
