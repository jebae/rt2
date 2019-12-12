function check_val(val)
{
    return ((val == '') ? "0" : val);
}

function check_multi_val(vals)
{
    var final = [3];

    final[0] = (vals[0].value == '') ? "0" : vals[0].value;
    final[1] = (vals[1].value == '') ? "0" : vals[1].value;
    final[2] = (vals[2].value == '') ? "0" : vals[2].value;
    return (final);
}

function get_sph_att(tmp)
{
    var sph_cen = check_multi_val(document.getElementsByName('center_s')); 
    var sph_rad = check_val(document.getElementById('sph_rad').value);

    tmp = "\t\t\t<center> " + sph_cen[2] + ", " + sph_cen[1] + ", " + sph_cen[0] + " </center>\n";
    tmp += "\t\t\t<radius> " + sph_rad + " </radius>\n";
    return (tmp);
}

function get_con_att(tmp)
{
    var con_cen = check_multi_val(document.getElementsByName('center_c'));
    var con_axis = check_multi_val(document.getElementsByName('axis_c'));
    var con_ang = check_val(document.getElementById('con_ang').value);
    var con_uheight = check_val(document.getElementById('con_uheight').value);
    var con_lheight = check_val(document.getElementById('con_lheight').value);

    tmp = "\t\t\t<center> " + con_cen[2] + ", " + con_cen[1] + ", " + con_cen[0] + " </center>\n";
    tmp += "\t\t\t<axis> " + con_axis[2] + ", " + con_axis[1] + ", " + con_axis[0] + " </axis>\n";
    tmp += "\t\t\t<angle> " + con_ang + " </angle>\n";
    tmp += "\t\t\t<lower_height> " + con_lheight + " </lower_height>\n";
    tmp += "\t\t\t<upper_height> " + con_uheight + " </upper_height>\n";
    return (tmp);
}

function get_cyn_att(tmp)
{
    var cyn_cen = check_multi_val(document.getElementsByName('center_y'));
    var cyn_axis = check_multi_val(document.getElementsByName('axis_y'));
    var cyn_rad = check_val(document.getElementById('cyn_rad').value);
    var cyn_height = check_val(document.getElementById('cyn_height').value);

    tmp = "\t\t\t<center> " + cyn_cen[2] + ", " + cyn_cen[1] + ", " + cyn_cen[0] + " </center>\n";
    tmp += "\t\t\t<axis> " + cyn_axis[2] + ", " + cyn_axis[1] + ", " + cyn_axis[0] + " </axis>\n";
    tmp += "\t\t\t<radius> " + cyn_rad + " </radius>\n";
    tmp += "\t\t\t<height> " + cyn_height + " </height>\n";
    return (tmp);
}

function get_rec_att(tmp)
{
    var point = check_multi_val(document.getElementsByName('rec_point'));
    var vecA = check_multi_val(document.getElementsByName('rec_vector_a'));
    var vecB = check_multi_val(document.getElementsByName('rec_vector_b'));
    
    tmp = "\t\t\t<point> " + point[2] + ", " + point[1] + ", " + point[0] + " </point>\n";
    tmp += "\t\t\t<vector_a> " + vecA[2] + ", " + vecA[1] + ", " + vecA[0] + " </vector_a>\n";
    tmp += "\t\t\t<vector_b> " + vecB[2] + ", " + vecB[1] + ", " + vecB[0] + " </vector_b>\n";
    return(tmp);
}

function get_rin_att(tmp)
{
    var ring_cen = check_multi_val(document.getElementsByName('center_r'));
    var ring_nor = check_multi_val(document.getElementsByName('ri_normal'));
    var ring_inn_rad = check_val(document.getElementById('ring_inn_rad').value);
    var ring_out_rad = check_val(document.getElementById('ring_out_rad').value);

    tmp = "\t\t\t<center> " + ring_cen[2] + ", " + ring_cen[1] + ", " + ring_cen[0] + " </center>\n";
    tmp += "\t\t\t<normal> " + ring_nor[2] + ", " + ring_nor[1] + ", " + ring_nor[0] + " </normal>\n";
    tmp += "\t\t\t<outer_radius> " + ring_out_rad + " </outer_radius>\n";
    tmp += "\t\t\t<inner_radius> " + ring_inn_rad + " </inner_radius>\n";
    return(tmp);
}

function get_box_att(tmp)
{
    var box_point = check_multi_val(document.getElementsByName('box_point'));
    var box_vec_a = check_multi_val(document.getElementsByName('box_vector_a'));
    var box_vec_b = check_multi_val(document.getElementsByName('box_vector_b'));
    var box_lenC = check_val(document.getElementById('box_lenC').value);

    tmp = "\t\t\t<point> " + box_point[2] + ", " + box_point[1] + ", " + box_point[0] + " </point>\n";
    tmp += "\t\t\t<vector_a> " + box_vec_a[2] + ", " + box_vec_a[1] + ", " + box_vec_a[0] + " </vector_a>\n";
    tmp += "\t\t\t<vector_b> " + box_vec_b[2] + ", " + box_vec_b[1] + ", " + box_vec_b[0] + " </vector_b>\n";
    tmp += "\t\t\t<length_c> " + box_lenC + " </length_c>\n";
    return(tmp);
}

function get_pyr_att(tmp)
{
    var pyr_point = check_multi_val(document.getElementsByName('py_point'));
    var pyr_vecV = check_multi_val(document.getElementsByName('vector_u'));
    var pyr_vecU = check_multi_val(document.getElementsByName('vector_v'));
    var pyr_height = check_val(document.getElementById('pyr_height').value);

    tmp = "\t\t\t<point> " + pyr_point[2] + ", " + pyr_point[1] + ", " + pyr_point[0] + " </point>\n";
    tmp += "\t\t\t<vector_u> " + pyr_vecV[2] + ", " + pyr_vecV[1]  + ", " + pyr_vecV[0]  + " </vector_a>\n";
    tmp += "\t\t\t<vector_v> " + pyr_vecU[2] + ", " + pyr_vecU[1] + ", " + pyr_vecU[0] + " </vector_b>\n";
    tmp += "\t\t\t<height> " + pyr_height + " </height>\n";
    return(tmp);
}

function get_tri_att(tmp)
{
    var tri_point = check_multi_val(document.getElementsByName('tr_point'));
    var tri_vecAB = check_multi_val(document.getElementsByName('vector_ab'));
    var tri_vecAC = check_multi_val(document.getElementsByName('vector_ac'));

    tmp = "\t\t\t<center> " + tri_point[2] + ", " + tri_point[1] + ", " + tri_point[0] + " </center>\n";
    tmp += "\t\t\t<vector_ab> " + tri_vecAB[2] + ", " + tri_vecAB[1] + ", " + tri_vecAB[0] + " </vector_ab>\n";
    tmp += "\t\t\t<center_ac> " + tri_vecAC[2] + ", " + tri_vecAC[1] + ", " + tri_vecAC[0] + " </vector_ac>\n";
    return(tmp);
}

function get_pla_att(tmp)
{
    var pla_normal = check_multi_val(document.getElementsByName('pla_normal'));
    var pla_lenC = check_val(document.getElementById('pla_len_c'));

    tmp = "\t\t\t<center> " + pla_normal[2] + ", " + pla_normal[1] + ", " + pla_normal[0] + " </center>\n";
    tmp += "\t\t\t<length_c> " + pla_lenC.value + " </length_c>\n";
    return (tmp);
}

function get_parallel_attributes(shape_num)
{
    var tmp;
    var ior = document.getElementsByName('ior');
    var color_r = document.getElementsByName('color_r');
    var color_g = document.getElementsByName('color_g');
    var color_b = document.getElementsByName('color_b');
    var transparency = document.getElementsByName('transparency');

    tmp = "\t\t\t<ior> " + check_val(ior[shape_num].value) + " </ior>\n";
    tmp += "\t\t\t<color> " + check_val(color_r[shape_num].value) + ", " + check_val(color_g[shape_num].value) + ", " + check_val(color_b[shape_num].value) + " </color>\n";
    tmp += "\t\t\t<transparency> " + check_val(transparency[shape_num].value) + " </transparency>\n";
    return (tmp);
}

function get_mapping()
{
    var mapped = $('input[name=radio-207]:checked', '#mapping').val();
    if (mapped != null)
        return ("\t\t\t<texture_mapping> " + mapped + ".jpg </texture_mapping>\n");
    else
        return (0);
}

function get_bumping()
{
    var bumped = $('input[name=radio-208]:checked', '#bumping').val();
    if (bumped != null)
        return ("\t\t\t<texture_bumping> " + bumped + ".jpg </texture_bumping>\n");
    else
        return (0);
}

function close_shape(shape)
{
    return ("\t\t</" + shape + ">\n");
}

function create_xml(shape)
{
    var xml_shape = "\t\t<" + shape + ">\n";
    var shape_num = 0;
    var tmp;

    if (shape.localeCompare("sphere") == 0)
        xml_shape += get_sph_att(tmp);
    if (shape.localeCompare("cone") == 0)
    {
        shape_num = 1;
        xml_shape += get_con_att(tmp);
    }
    if (shape.localeCompare("cylinder") == 0)
    {
        shape_num = 2;
        xml_shape += get_cyn_att(tmp);
    }
    if (shape.localeCompare("rectangle") == 0)
    {
        shape_num = 3;
        xml_shape += get_rec_att(tmp);
    }
    if (shape.localeCompare("ring") == 0)
    {
        shape_num = 4;
        xml_shape += get_rin_att(tmp);
    }
    if (shape.localeCompare("box") == 0)
    {
        shape_num = 5;
        xml_shape += get_box_att(tmp);
    }
    if (shape.localeCompare("pyramid") == 0)
    {
        shape_num = 6;
        xml_shape += get_pyr_att(tmp);
    }
    if (shape.localeCompare("triangle") == 0)
    {
        shape_num = 7;
        xml_shape += get_tri_att(tmp);
    }
    if (shape.localeCompare("plane") == 0)
    {
        shape_num = 8;
        xml_shape += get_pla_att(tmp);
    }

    // attributes in every shape
    xml_shape += get_parallel_attributes(shape_num);

    // adding texture
    if ((shape.localeCompare("sphere") == 0) || (shape.localeCompare("cone") == 0)
        || (shape.localeCompare("rectangle") == 0) || (shape.localeCompare("cylinder") == 0))
    {
        var temp_map = get_mapping();
        if (temp_map != 0)
            xml_shape += temp_map;

        var temp_bump = get_bumping();
        if (temp_bump != 0)
            xml_shape += temp_bump;
    }

    xml_shape += close_shape(shape);
    console.log("i am the output ---->\n\n", xml_shape, "\n\n");
    
    function read_write_file (shape_num){
        var testing = "file_" + shape_num; 
        var file = document.getElementById(testing).files[0];
        console.log(file.name, "\n\n");

        var reader = new FileReader();
        reader.onload = function(progressEvent) {
            // Entire file
            // console.log(this.result);
        
            // By lines
            var lines = this.result.split('\n');
            for(var line = 0; line < lines.length; line++){
                console.log(lines[line]);
            }
            
        };
        reader.readAsText(file);
    };
    read_write_file(shape_num)

    // attempting to write to file here
    // this reload file !
    // document.location.reload(true);
}

function add_shape_div() 
{
    // appends text to OBJECTS div that is the options in first part fo div, Returns the selected value.
    var sel = document.getElementById("object_options");
    var first = document.createElement("div");
    first.setAttribute("id", "chosen_shape");
    first.innerHTML =
    'You have chosen <span id="shape_chosen_text">' +
    sel.value +
    "</span> !";
    document.getElementById("objects").appendChild(first);
    return sel.value;
}

function show_shape_form(selected)
{
    // displays form for selected shape
    var new_selected = selected + "_object";
    const string = String(new_selected);
    var show = document.getElementById(string);
    show.style.display = 'block';

    if ((selected.localeCompare("sphere") == 0) || (selected.localeCompare("cone") == 0) 
        || (selected.localeCompare("rectangle") == 0) || (selected.localeCompare("cylinder") == 0))
    {
        var textures = document.getElementById("main_textures");
        textures.style.display = 'block';
        var button = document.createElement("input");
        button.setAttribute("class", "buttons");
        button.setAttribute("id", "button_" + selected);
        button.setAttribute("type", "button");
        button.onclick = () => create_xml(selected);
        button.setAttribute("value", "ADD " + selected.toUpperCase() + " !");
        document.getElementById("the_form_container").appendChild(button);
    }
}

function select_shape_form(selected) 
{
    // creates the div that will hold the form
    const object_string = String(selected);
    var object = document.createElement("div");
    object.setAttribute("id", "object_chosen");

    if (selected.localeCompare("NO SHAPE") == 0)
    {
        object.setAttribute("class", "button_" + object_string);
        object.innerHTML = '<h3>NOTHING WILL BE <span id="selected_shape">MODIFIED</span>!</h3><br/>';
        document.getElementById("the_form_container").appendChild(object);
    } 
    else 
    {
        if (selected.localeCompare("sphere") == 0)
            show_shape_form(object_string);
        else if (selected.localeCompare("cone") == 0)
            show_shape_form(object_string);
        else if (selected.localeCompare("cylinder") == 0)
            show_shape_form(object_string);
        else if (selected.localeCompare("plane") == 0)
            show_shape_form(object_string);
        else if (selected.localeCompare("rectangle") == 0)
            show_shape_form(object_string);
        else if (selected.localeCompare("box") == 0)
            show_shape_form(object_string);
        else if (selected.localeCompare("triangle") == 0)
            show_shape_form(object_string);
        else if (selected.localeCompare("pyramid") == 0)
            show_shape_form(object_string);
        else if (selected.localeCompare("ring") == 0)
            show_shape_form(object_string);
    }
}

function select_object() 
{
    // hides the select drop down bar 
    var divsToHide = document.getElementsByClassName("objects");
    for (var i = 0; i < divsToHide.length; i++) {
        for (var j = 0; j < divsToHide[i].childNodes.length; j++) {
            if (
            divsToHide[i].childNodes[j] &&
            divsToHide[i].childNodes[j].style
            ) {
            divsToHide[i].childNodes[j].style.visibility = "hidden";
            divsToHide[i].childNodes[j].style.display = "none";
            }
        }
    }
    var selected = add_shape_div();
    select_shape_form(selected);
}