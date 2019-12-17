const express = require("express");
const bodyParser = require('body-parser');
const fs = require('fs');
const xmlParser = require("xml2json")
const formatXml = require("xml-formatter")

const app = express();

app.use(bodyParser.json());       // to support JSON-encoded bodies
app.use(bodyParser.urlencoded({     // to support URL-encoded bodies
  extended: true
})); 

// server configuration
const PORT = 8080;

// for css and js
app.use(express.static('public'));

// get method
app.get('/',function(req,res) {
  res.sendFile(__dirname + '/index.html');
});

// create a route for the app
app.post('/xmlwrite', (req, res) => {

  fs.readFile( req.body.filename, function modify_xml(err, data) 
  {
    if (err) {
      res.json({warning:"No file given."});
      return;  
    }
    const xmlObj = xmlParser.toJson(req.body.data, {reversible: true, object: true})
    const xmlFile = xmlParser.toJson(data, {reversible: true, object: true})

    if (xmlFile.hasOwnProperty("scene") && xmlFile.scene.hasOwnProperty("objects"))
    {
      const xmlFileObj = xmlFile["scene"]["objects"]
      const objectName = Object.keys(xmlObj)[0];
      var count = Object.keys(xmlFileObj).length

      if (Array.isArray(xmlFile.scene.objects[objectName])) {
        xmlFile.scene.objects[objectName].push(xmlObj[objectName]);
      } else if (xmlFile.scene.objects[objectName]) {
        xmlFile.scene.objects[objectName] = [xmlFile.scene.objects[objectName], xmlObj[objectName]]
      } else {
        Object.assign(xmlFile["scene"]["objects"], xmlObj)
      }

      const stringifiedXmlObj = JSON.stringify(xmlFile)
      const finalXml = xmlParser.toXml(stringifiedXmlObj)

      // writing to file 
      fs.writeFile(req.body.filename, formatXml(finalXml, {collapseContent: true}), function(err, result){
        if (err) {
          console.log("Nothing written to the file.")
          res.json({bad:"Failed!"});
        } else {
          console.log("Xml file successfully updated.")
          res.json({good:"Success!"});
        }
      })
    }
  })
});

// make the server listen to requests
app.listen(PORT, () => {
  console.log(`Server running at: http://localhost:${PORT}/`);
});