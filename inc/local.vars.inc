<?php

function local_variables_get_array(){
  $vars = array();

  // client data
  $vars["client"]["name"] = variable_get("local_client_name", FALSE);

  $vars["client"]["address"] = array(
    "street" => variable_get("local_client_address_street", FALSE),
    "city"   => variable_get("local_client_address_city", FALSE),
    "state"  => variable_get("local_client_address_state", FALSE),
    "zip"    => variable_get("local_client_address_zip", FALSE),
  );

  $vars["client"]["phone"] = variable_get("local_client_phone", FALSE);

  $vars["client"]["email"] = variable_get("local_client_email", FALSE);

  $vars["client"]["registrar"] = array(
    "name" => variable_get("local_client_registrar_name", FALSE),
    "user" => variable_get("local_client_registrar_user", FALSE),
    "pass" => variable_get("local_client_registrar_pass", FALSE),
  );

  // seo data
  $vars["name"] = variable_get("local_name", false);

  $vars["address"] = array(
    "street" => variable_get("local_address_street", FALSE),
    "city"   => variable_get("local_address_city", FALSE),
    "state"  => variable_get("local_address_state", FALSE),
    "zip"    => variable_get("local_address_zip", FALSE),
  );

  $vars["phone"] = variable_get("local_phone", FALSE);

  $vars["email"] = variable_get("local_email", FALSE);

  $vars["hours"] = array(
    "mo" => array(
      "status" => variable_get("local_hours_mo_status", FALSE),
      "open"   => variable_get("local_hours_mo_open", FALSE),
      "close"  => variable_get("local_hours_mo_close", FALSE),
    ),

    "tu" => array(
      "status" => variable_get("local_hours_tu_status", FALSE),
      "open"   => variable_get("local_hours_tu_open", FALSE),
      "close"  => variable_get("local_hours_tu_close", FALSE),
    ),

    "we" => array(
      "status" => variable_get("local_hours_we_status", FALSE),
      "open"   => variable_get("local_hours_we_open", FALSE),
      "close"  => variable_get("local_hours_we_close", FALSE),
    ),

    "th" => array(
      "status" => variable_get("local_hours_th_status", FALSE),
      "open"   => variable_get("local_hours_th_open", FALSE),
      "close"  => variable_get("local_hours_th_close", FALSE),
    ),

    "fr" => array(
      "status" => variable_get("local_hours_fr_status", FALSE),
      "open"   => variable_get("local_hours_fr_open", FALSE),
      "close"  => variable_get("local_hours_fr_close", FALSE),
    ),

    "sa" => array(
      "status" => variable_get("local_hours_sa_status", FALSE),
      "open"   => variable_get("local_hours_sa_open", FALSE),
      "close"  => variable_get("local_hours_sa_close", FALSE),
    ),

    "su" => array(
      "status" => variable_get("local_hours_su_status", FALSE),
      "open"   => variable_get("local_hours_su_open", FALSE),
      "close"  => variable_get("local_hours_su_close", FALSE),
    ),
  );

  $vars["logo"]   = variable_get("local_logo", FALSE);

  $vars["domain"] = variable_get("local_domain", FALSE);

  //required
  $vars["social"]["facebook"]    = variable_get("local_social_facebook", FALSE);
  $vars["social"]["twitter"]     = variable_get("local_social_twitter", FALSE);
  $vars["social"]["google_plus"] = variable_get("local_social_google_plus", FALSE);
  $vars["social"]["linkedin"]    = variable_get("local_social_linkedin", FALSE);
  $vars["social"]["instagram"]   = variable_get("local_social_instagram", FALSE);
  $vars["social"]["pinterest"]   = variable_get("local_social_pinterest", FALSE);
  $vars["social"]["youtube"]     = variable_get("local_social_youtube", FALSE);

  //optional
  $vars["social"]["myspace"]     = variable_get("local_social_myspace", FALSE);
  $vars["social"]["soundcloud"]  = variable_get("local_social_soundcloud", FALSE);
  $vars["social"]["tumblr"]      = variable_get("local_social_tumblr", FALSE);

  array_filter($vars);

  return $vars;
}

function local_variables_get_keys(){
  $vars = local_variables_get_array();
  $keys = array();

  foreach($vars as $var_key => $var_val){
    if(is_array($var_val)){
      foreach($var_val as $key => $val){
        if(is_array($val)){
          foreach($val as $k => $v){
            $keys[]="local_".$var_key."_".$key."_".$k;
          }
        } else {
          $keys[]="local_".$var_key."_".$key;
        }
      }
    } else {
      $keys[]="local_".$var_key;
    }
  }

  return $keys;
}

function local_variables_flush(){
  $vars = local_variables_get_keys();

  foreach($vars as $var){
    if(!variable_get($var, FALSE) == FALSE){
      variable_del($var);
    }
  }
}
