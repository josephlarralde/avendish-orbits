autowatch = 1;

// see https://en.wikipedia.org/wiki/N-sphere#Spherical_coordinates
// for a generalization of spher2car / car2spher in N dimensions

var theta = 0;
var phi = 0;

var sp = 33 * 0.001; // sampling period

var t1 = 1;
var step1 = sp / t1;
var t2 = 1;
var step2 = sp / t2;

var phase1 = 0;
var phase2 = 0;

var PI = Math.PI;

function randomOverRange(halfRange) {
	//return (Math.random() * 2 - 1) * halfRange;
	return Math.random() * halfRange;
}

function sphericalToCartesian(angles) {
	if (!Array.isArray(angles)) return null;
	if (angles.length < 1) return null;
	
	var sinProduct = 1;
	var res = [];
	
	for (var i = 0; i < angles.length; ++i) {
		res.push(sinProduct * Math.cos(angles[i]));
		sinProduct *= Math.sin(angles[i]);
	}
	
	res.push(sinProduct);
	return res;
}

function frequencies(f1, f2) {
	t1 = 1 / (f1);
	t2 = 1 / (f2);
	step1 = sp / t1;
	step2 = sp / t2;
	
	//post(f1, f2, "\n");
	//post(t1, t2, "\n");
}

function bang() {
	phase1 += step1;
	if (phase1 > 1) phase1 = phase1 - Math.floor(phase1);
	
	theta = phase1 * 2 * PI - PI;
	//if (theta > PI) theta -= 2 * PI;
	//if (theta < -PI) theta += 2 * PI;
	
	phase2 += step2;
	if (phase2 > 1) phase2 = phase2 - Math.floor(phase2);

	phi = phase2 * 2 * PI - PI;
	//if (phi > 2 * PI) phi -= 2 * PI;
	//if (phi < 0) phi += 2 * PI;
	
	const coords = sphericalToCartesian([theta, phi]);
	outlet(0, coords);
}