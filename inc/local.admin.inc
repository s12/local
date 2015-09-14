<?php

if(!function_exists("local_variables_get_array")){
  module_load_include("inc", "local", "inc/local.vars");
}

function local_admin_settings(){
  $form["contact"] = array(
    "#type" => "fieldset",
    "#title" => "Local Business Contact Info",
    "#description" => "NAP (Name, Address, Phone) / Email",
  );
  
  $form["contact"]["local_name"] = array(
    "#type" => "textfield",
    "#title" => t("Name"),
    "#default_value" => variable_get("local_name", variable_get("site_name", FALSE)),
    "#description" => t("Enter the preferred full name of the business. Assuming you've already changed the site name you can probably leave the default value as is, if not you should probably go change the site information first. @link", array("@link" => "<a href=\"/admin/config/system/site_information\" title=\"Edit: Site Information\" target=\"_blank\">Site information</a>")),
    
  );
  
  $form["contact"]["address"] = array(
    "#type" => "fieldset",
    "#title" => "Local Business Address",
    "#description" => "The primary address of the business.",
  );
  
  $form["contact"]["address"]["street"] = array(
    "#type" => "textfield",
    "#title" => t("Street address"),
    "#default_value" => variable_get("local_address_street", FALSE),
  );

  
  $form["contact"]["address"]["city"] = array(
    "#type" => "textfield",
    "#title" => t("City"),
    "#default_value" => variable_get("local_address_city", FALSE),
  );

  
  $form["contact"]["address"]["state"] = array(
    "#type" => "select",
    "#title" => t("State"),
    "#default_value" => variable_get("local_address_state", "none"),
    "#options" => array(
      "none" => "====== SELECT ONE ======",
      "ak" => t("AK (Alaska)"),
      "al" => t("AL (Alabama)"),
      "ar" => t("AR (Arkansas)"),
      "az" => t("AZ (Arizona)"),
      "ca" => t("CA (California)"),
      "co" => t("CO (Colorado)"),
      "ct" => t("CT (Connecticut)"),
      "de" => t("DE (Delaware)"),
      "fl" => t("FL (Florida)"),
      "ga" => t("GA (Georgia)"),
      "hi" => t("HI (Hawaii)"),
      "ia" => t("IA (Iowa)"),
      "id" => t("ID (Idaho)"),
      "il" => t("IL (Illinois)"),
      "in" => t("IN (Indiana)"),
      "ks" => t("KS (Kansas)"),
      "ky" => t("KY (Kentucky)"),
      "la" => t("LA (Louisiana)"),
      "ma" => t("MA (Massachusetts)"),
      "md" => t("MD (Maryland)"),
      "me" => t("ME (Maine)"),
      "mi" => t("MI (Michigan)"),
      "mn" => t("MN (Minnesota)"),
      "mo" => t("MO (Missouri)"),
      "ms" => t("MS (Mississippi)"),
      "mt" => t("MT (Montana)"),
      "nc" => t("NC (North Carolina)"),
      "nd" => t("ND (North Dakota)"),
      "ne" => t("NE (Nebraska)"),
      "nh" => t("NH (New Hampshire)"),
      "nj" => t("NJ (New Jersey)"),
      "nm" => t("NM (New Mexico)"),
      "nv" => t("NV (Nevada)"),
      "ny" => t("NY (New York)"),
      "oh" => t("OH (Ohio)"),
      "ok" => t("OK (Oklahoma)"),
      "or" => t("OR (Oregon)"),
      "pa" => t("PA (Pennsylvania)"),
      "ri" => t("RI (Rhode Island)"),
      "sc" => t("SC (South Carolina)"),
      "sd" => t("SD (South Dakota)"),
      "tn" => t("TN (Tennessee)"),
      "tx" => t("TX (Texas)"),
      "ut" => t("UT (Utah)"),
      "va" => t("VA (Virginia)"),
      "vt" => t("VT (Vermont)"),
      "wa" => t("WA (Washington)"),
      "wi" => t("WI (Wisconsin)"),
      "wv" => t("WV (West Virginia)"),
      "wy" => t("WY (Wyoming)"),
    ),
  );
  
  $form["contact"]["address"]["zip"] = array(
    "#type" => "textfield",
    "#title" => t("Zip"),
    "#size" => 10,
    "#maxlength" => 5,
    "#default_value" => variable_get("local_address_zip", FALSE),
    "#attributes" => array(
      "pattern" => "/^\d{5}$/",
      "placeholder" => "28786",
    ),
  );
  
  $form["contact"]["phone"] = array(
    "#type" => "textfield",
    "#title" => t("Phone"),
    "#size" => 24,
    "#maxlength" => 12,
    "#default_value" => variable_get("local_phone", FALSE),
    "#description" => t("XXX-XXX-XXXX <em>10-digit phone number separated with dashes.</em>"),
    "#attributes" => array(
      "pattern" => "/^\d{3}-\d{3}-\d{4}$/",
      "placeholder" => "828-246-9552",
      "onblur" => "(function($){if(!$(this).attr('pattern').test(this.val())){$(this).addClass('has-error').focus().append('<em id=\"error_local_phone\" class=\"err-msg\">That's not a phone number, try again!</em>');}else{$(this).removeClass('has-error');$('#error_local_phone').remove();}})(jQuery)"
    ),
  );
}
