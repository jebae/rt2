const express = require("express");
const bodyParser = require('body-parser');
// require(file read and write);

const app = express();

app.use(bodyParser.json());       // to support JSON-encoded bodies
app.use(bodyParser.urlencoded({     // to support URL-encoded bodies
  extended: true
})); 

// create new express app and save it as "app"

// server configuration
const PORT = 8080;

// create a route for the app
app.post('/xmlwrite', (req, res) => {
  console.log(req.body.data);
  	// find location (after <object> !) in xml
	// 	add data

});

// make the server listen to requests
app.listen(PORT, () => {
  console.log(`Server running at: http://localhost:${PORT}/`);
});