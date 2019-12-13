const express = require("express");
const bodyParser = require('body-parser');
const fs = require('fs');
const xmlParser = require("xml2json")
const formatXml = require("xml-formatter")

const app = express();
// const reload = require('express-reload')
// var path = __dirname + '/'
// console.log(__dirname);
// or like this for a non index.js name
// var path = __dirname + '/project/server.js'

// app.use(reload(path)) // for hot reload !

app.use(bodyParser.json());       // to support JSON-encoded bodies
app.use(bodyParser.urlencoded({     // to support URL-encoded bodies
  extended: true
})); 

// server configuration
const PORT = 8080;

// create a route for the app
app.post('/xmlwrite', (req, res) => {
  // console.log(req.body.data) 
  // console.log(req.body.filename)
  // find location (after <object> !) in xml
  // 	add data  

  fs.readFile( req.body.filename, function modify_xml(err, data) 
  {
    if (err) {
      throw err;
    }
    const xmlObj = xmlParser.toJson(req.body.data, {reversible: true, object: true})
    const xmlFile = xmlParser.toJson(data, {reversible: true, object: true})
    const xmlFileObj = xmlFile["scene"]["objects"]

    if (xmlFile.hasOwnProperty("scene") && xmlFile.scene.hasOwnProperty("objects"))
    {
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
          console.log("err")
        } else {
          console.log("Xml file successfully updated.")
        }
      })
    }
  })
});

// make the server listen to requests
app.listen(PORT, () => {
  console.log(`Server running at: http://localhost:${PORT}/`);
});