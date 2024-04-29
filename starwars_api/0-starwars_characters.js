const request = require('request');
function get_sw_data(movie) {
	request('https://swapi-api.hbtn.io/api/films/' , function (error, response, body) {
		jo = JSON.parse(body);
		index = 0;
		for (each in jo['results']) {
			if (jo['results'][each]['episode_id'] == movie)
				index = each;
		}
		for (each in jo['results'][index]['characters']) {
			request(jo['results'][index]['characters'][each], function (error, response, body) {
				console.log(JSON.parse(body)['name']);
			});
		}
	});
}

get_sw_data(process.argv[2]);
