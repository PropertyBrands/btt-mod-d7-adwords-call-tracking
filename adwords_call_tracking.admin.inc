<?php
/**
 * Settings form for AdWords call tracking
 */
function adwords_call_tracking_settings($form) {
  global $conf;
  $form = array();

  $form['adwords_call_tracking_default_number_source'] = array(
    '#type' => 'select',
    '#options' => array(
      'number' => t('I will provide a number'),
      'variable' => t('I will use a system variable')
    ),
    '#title' => t('Default number source'),
    '#description' => t('Select where to obtain the default value for the phone number'),
    '#default_value' => variable_get('adwords_call_tracking_default_number_source', 'number'),
  );

  $form['adwords_call_tracking_default_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Default phone number'),
    '#description' => t('This number will be used when users land on your site from other sources'),
    '#default_value' => variable_get('adwords_call_tracking_default_number', ''),
    '#states' => array(
      'visible' => array(
        ':input[name="adwords_call_tracking_default_number_source"]' => array('value' => 'number')
      )
    ),
  );

  $form['adwords_call_tracking_default_variable'] = array(
    '#type' => 'select',
    '#title' => t('Default phone number variable'),
    '#description' => t('This variable will be used to supply the default phone number'),
    '#default_value' => variable_get('adwords_call_tracking_default_variable', ''),
    '#options' => drupal_map_assoc(array_keys($conf)),
    '#states' => array(
      'visible' => array(
        ':input[name="adwords_call_tracking_default_number_source"]' => array('value' => 'variable')
      )
    ),
  );

  $form['adwords_call_tracking_css_selectors'] = array(
    '#type' => 'textarea',
    '#title' => t('CSS Selectors'),
    '#description' => t('Elements that match this string of selectors will have their content replaced with the Google forwarding number for tracking.'),
    '#default_value' => variable_get('adwords_call_tracking_css_selectors')
  );

  $form['adwords_call_tracking_code'] = array(
    '#type' => 'textarea',
    '#title' => t('Conversion Code'),
    '#description' => t('Add your Google AdWords call tracking script here. For more information please see: <a href="https://support.google.com/adwords/answer/1722054#calls_from_websitesim">https://support.google.com/adwords/answer/1722054#calls_from_websitesim</a>'),
    '#default_value' => variable_get('adwords_call_tracking_code', '')
  );
  drupal_set_title('Configure AdWords Call Tracking');
  return system_settings_form($form);
}