/**
* Connecteur MQTT-PostgreSQL pour le projet JardinIoT
* Club CÉDILLE
* ----
* Écrit par Aubert Guillemette
*
* version 0.2, 6 mars 2017
*  -Ajout d'une fonction qui subscribe automatiquement
*   à tous les sensors dans la base de données
* version 0.1, 5 mars 2017
*  -Première version
*/


//----------------------------SECTION CONFIGURATION----------------------------

//Constantes d'application
const DEBUG = true;

const MQTT_USERNAME = 'jardiniot';
const MQTT_PASSWORD = 'jardiniot';
const MQTT_IP       = '192.168.56.101';
const MQTT_PORT     = '1883';

const PG_USER       = 'jardiniot';
const PG_PASS       = 'jardiniot';
const PG_DB         = 'jardiniot';
const PG_IP         = 'localhost';
const PG_PORT       = '5432';

//-----------------------------------------------------------------------------



//Construction des chaînes de connexion
const MQTT_CREDS    = { username: MQTT_USERNAME, password: MQTT_PASSWORD };
const MQTT_CONN_STR = 'mqtt://' + MQTT_IP + ':' + MQTT_PORT;
const PG_CONN_STR   = 'postgres://'.concat(PG_USER, ':', PG_PASS, '@', PG_IP, ':', PG_PORT, '/', PG_DB);

//Requirements
var pg = require('pg');
var mqtt = require('mqtt');



//Démarrage du client MQTT
debug("Connexion au serveur PostgreSQL...");
var pg_client = new pg.Client(PG_CONN_STR);
debug("Connecté.");

debug("Connexion au serveur MQTT...");
var mqtt_client = mqtt.connect(MQTT_CONN_STR, MQTT_CREDS);

//Callbacks!
mqtt_client.on('connect', function () {
	debug("Connecté. Récupération des sensors...");

	//On va chercher tous les sensors auxquels on doit subscriber dans
	//la base de données.
	retrieveSensors(function(topics){

		topics.forEach(function(topic){
			debug("Subscribing to topic " + topic);
			mqtt_client.subscribe(topic);
		});

	});

});

//Ajouter les messages reçus dans la base de données
mqtt_client.on('message', function (topic, message) {
	debug("-------------------\nMessage recu:\nTopic: " + topic + ", Message: " + message);
	addToDatabase(topic, message);
	//mqtt_client.end(); //On ne ferme pas le client!
});

//Gestion des erreurs
mqtt_client.on('error', function(error) {
	console.log("Error: " + error);
	//process.exit(1);
});





//Fonction pour ajouter les messages reçus dans la base de données
function addToDatabase(sensor_id, sensor_message)
{
	pg_client.connect();

	var query = pg_client.query('INSERT INTO values (sensor_id, value, timestamp) VALUES ($1, $2, $3)', [sensor_id, sensor_message, Date.now()]);

	query.on('end', function() {
		pg_client.end();
	});
}


//Fonction qui affiche des messages à l'écran si la constante DEBUG est true
function debug(msg)
{
	if (DEBUG) { console.log(msg); }
}

//Fonction pour aller chercher la liste des sensors auxquels subscriber dans la base de données
function retrieveSensors(callback)
{
	pg_client.connect();

	var query = pg_client.query('select * from sensors');
	var sensorArray = [];

	query.on('row', function(row) {
		debug(row.id + " - " + row.name + ", is type " + row.type + ", from bucket " + row.bucket_id);
		sensorArray.push(row.id.toString());
	});

	query.on('end', function() {
		pg_client.end();
		callback(sensorArray);
	});

}
